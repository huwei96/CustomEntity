#pragma once
#include "FaneTriangle.h"
using namespace Autodesk::AutoCAD::DatabaseServices;
using namespace Autodesk::AutoCAD::Geometry;
using namespace System;

namespace CustomEntity {
	[Autodesk::AutoCAD::Runtime::Wrapper("FaneTriangle")]
	public ref class FaneTriangleWrapper : public Autodesk::AutoCAD::DatabaseServices::Entity
	{
		// TODO: 在此处添加此类的方法。
	public:
		FaneTriangleWrapper();
		FaneTriangleWrapper(Point3d pt1, Point3d pt2, Point3d pt3);

		void GetVerts([Runtime::InteropServices::Out] Autodesk::AutoCAD::Geometry::Point3dCollection ^%verts);

		double GetArea();

		void SetVertAt(int index, Point3d pt);

	internal:
		FaneTriangleWrapper(System::IntPtr unmanagedPointer, bool autoDelete);
		inline FaneTriangle* GetImpObj() {
			return static_cast<FaneTriangle*>(UnmanagedObject.ToPointer());
		}
	};
}
