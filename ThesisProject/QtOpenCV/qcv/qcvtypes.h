
#ifndef QCV_TYPES_H
#define QCV_TYPES_H

#include <cv.h>
#include <highgui.h>
#include <QtCore>

//====================================================================
// CvPoint
//====================================================================

inline CvPoint qcvPoint(int x, int y){ return cvPoint(x,y); }
inline CvPoint qcvPoint(const QPoint &p){ return qcvPoint(p.x(), p.y()); }
inline QPoint  qcvPoint(const CvPoint &p){ return QPoint(p.x, p.y); }

inline bool operator==(const CvPoint &p1, const CvPoint &p2)
	{ return ((p1.x==p2.x) && (p1.y==p2.y)); }
inline bool operator!=(const CvPoint &p1, const CvPoint &p2)
	{ return !(p1==p2); }

inline QDataStream& operator>>(QDataStream &in, CvPoint &p)
	{ return (in  >> p.x >> p.y); }
inline QDataStream& operator<<(QDataStream &out, const CvPoint &p)
	{ return (out << p.x << p.y); }

Q_DECLARE_METATYPE(CvPoint)

// CvPoint2D32f

inline QDataStream& operator>>(QDataStream &in, CvPoint2D32f &p)
	{ return (in  >> p.x >> p.y); }
inline QDataStream& operator<<(QDataStream &out, const CvPoint2D32f &p)
	{ return (out << p.x << p.y); }

Q_DECLARE_METATYPE(CvPoint2D32f)

// CvPoint2D64f

inline QDataStream& operator>>(QDataStream &in, CvPoint2D64f &p)
	{ return (in  >> p.x >> p.y); }
inline QDataStream& operator<<(QDataStream &out, const CvPoint2D64f &p)
	{ return (out << p.x << p.y); }

Q_DECLARE_METATYPE(CvPoint2D64f)

// CvPoint3D32f

inline QDataStream& operator>>(QDataStream &in, CvPoint3D32f &p)
	{ return (in  >> p.x >> p.y >> p.z); }
inline QDataStream& operator<<(QDataStream &out, const CvPoint3D32f &p)
	{ return (out << p.x << p.y << p.z); }

Q_DECLARE_METATYPE(CvPoint3D32f)

// CvPoint3D64f

inline QDataStream& operator>>(QDataStream &in, CvPoint3D64f &p)
	{ return (in  >> p.x >> p.y >> p.z); }
inline QDataStream& operator<<(QDataStream &out, const CvPoint3D64f &p)
	{ return (out << p.x << p.y << p.z); }

Q_DECLARE_METATYPE(CvPoint3D64f)

//====================================================================
// CvRect
//====================================================================

inline CvRect qcvRect(int x, int y, int w, int h)
	{ return cvRect(x, y, w, h); }
inline CvRect qcvRect(const QRect &r)
	{ return cvRect(r.x(), r.y(), r.width(), r.height()); }
inline QRect qcvRect(const CvRect &r)
	{ return QRect(r.x, r.y, r.width, r.height); }

inline bool operator==(const CvRect &r1, const CvRect &r2)
	{ return ((r1.x==r2.x) && (r1.y==r2.y) && (r1.width==r2.width) && (r1.height==r2.height)); }
inline bool operator!=(const CvRect &r1, const CvRect &r2)
	{ return !(r1==r2); }

inline QDataStream& operator>>(QDataStream &in, CvRect &r)
	{ return (in  >> r.x >> r.y >> r.width >> r.height); }
inline QDataStream& operator<<(QDataStream &out, const CvRect &r)
	{ return (out << r.x << r.y << r.width << r.height); }

Q_DECLARE_METATYPE(CvRect)

//====================================================================
// CvSize
//====================================================================

inline CvSize qcvSize(int w, int h)
	{ return cvSize(w, h); }
inline CvSize qcvSize(const QSize &s)
	{ return cvSize(s.width(), s.height()); }
inline QSize qcvSize(const CvSize &s)
	{ return QSize(s.width, s.height); }

inline bool operator==(const CvSize &r1, const CvSize &r2)
	{ return ((r1.width==r2.width) && (r1.height==r2.height)); }
inline bool operator!=(const CvSize &r1, const CvSize &r2)
	{ return !(r1==r2); }

inline QDataStream& operator>>(QDataStream &in, CvSize &size)
	{ return (in  >> size.width >> size.height); }
inline QDataStream& operator<<(QDataStream &out, const CvSize &size)
	{ return (out << size.width << size.height); }

Q_DECLARE_METATYPE(CvSize)

// CvSize2D32f

inline QDataStream& operator>>(QDataStream &in, CvSize2D32f &size)
	{ return (in  >> size.width >> size.height); }
inline QDataStream& operator<<(QDataStream &out, const CvSize2D32f &size)
	{ return (out << size.width << size.height); }

Q_DECLARE_METATYPE(CvSize2D32f)

//====================================================================
// other
//====================================================================

// CvScalar

inline QDataStream& operator>>(QDataStream &in, CvScalar &s)
	{ return (in  >> s.val[0] >> s.val[1] >> s.val[2] >> s.val[3]); }
inline QDataStream& operator<<(QDataStream &out, const CvScalar &s)
	{ return (out << s.val[0] << s.val[1] << s.val[2] << s.val[3]); }

Q_DECLARE_METATYPE(CvScalar)

//

#endif	// QCV_TYPES_H
