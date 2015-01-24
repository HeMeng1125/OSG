#include <windows.h>     
#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/ViewerEventHandlers>
#include <iostream>

osg::ref_ptr<osg::Node> MatrixOperation()
{
	osg::ref_ptr<osg::Group> group=new osg::Group;

	group->addChild(osgDB::readNodeFile("glider.osg"));

	return group;
}

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer=new osgViewer::Viewer;
	viewer->setSceneData(MatrixOperation().get());

	return viewer->run();
}