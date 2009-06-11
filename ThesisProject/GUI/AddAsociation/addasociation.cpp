#include "addasociation.h"

/**
 * This method sets up the GUI to add <Gesture,Event>
 * association.
 */

AddAsociation::AddAsociation(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

AddAsociation::~AddAsociation()
{
;
}

/**
 * This method fills the list and starts the event Loop.
 */

int AddAsociation::exec(GestureModel* gest, EventModel* key, EventModel* comb, EventModel* app, EventModel* open){

	ui.asociacionesView->clear();

	initVariables();

	ui.gestosView->clear();

	fillGestureList(gest);

	ui.eventosView->clear();

	fillEventList(key);
	fillEventList(comb);
	fillEventList(app);
	fillEventList(open);

	return QDialog::exec();
}

/**
 * This method initializes the variables which will store the
 * user's selection.
 */

void AddAsociation::initVariables(){
	gstring = 0;
	estring = 0;
	events = new QList<QString*>();
	gestures = new QList<QString*>();
}

/**
 * This method fills the EventList with the events in
 * the model
 */
void AddAsociation::fillGestureList(GestureModel* gm){
	gm->begin();
	Gesture* g;
	while (gm->hasNext()){
		g = gm->getNextGesture();
		QString* id = new QString(g->getId().c_str());
		QListWidgetItem *qListItem = new QListWidgetItem(ui.gestosView);
		qListItem->setText(*id);
		delete (id);
		gm->next();
	}
}

/**
 * This method fills the GestureList with the gestures in
 * the model
 */

void AddAsociation::fillEventList(EventModel* em){
	em->begin();
	Event* e;
	while (em->hasNext()){
		e = em->getNextEvent();
		QString* id = new QString(e->getId().c_str());
		QListWidgetItem *qListItem = new QListWidgetItem(ui.eventosView);
		qListItem->setText(*id);
		delete (id);
		em->next();
	}
}

/**
 * This method saves the item clicked in the Event View.
 */

void AddAsociation::saveEventClicked(QListWidgetItem* item){
	estring = new QString(item->text());
	if (gstring!=0)
		ui.addAsociacion->setEnabled(true);
}

/**
 * This method saves the item clicked in the Gesture View
 */

void AddAsociation::saveGestureClicked(QListWidgetItem* item){
	gstring = new QString(item->text());
	if (estring!=0)
		ui.addAsociacion->setEnabled(true);
}

/**
 * This method adds the association to the internal structure
 * and shows them on the association view
 */

void AddAsociation::addSelectedItems(){

	QString* toshow = new QString(*gstring + " <-> " + *estring);

	QList<QListWidgetItem *> list = ui.asociacionesView->findItems(*toshow,Qt::MatchExactly);

	if (list.size()>0)
		return;

	events->append(estring);
	gestures->append(gstring);

	QListWidgetItem *qListItem = new QListWidgetItem(ui.asociacionesView);
	qListItem->setText(*toshow);
	gstring = 0;
	estring = 0;
	ui.addAsociacion->setEnabled(false);
}
