#include "SceneYobject.h"
#include <stdexcept>

SceneYobject::SceneYobject(int id,
                           int parentId,
                           PluginList* pluginList)
                           : Yobject(id,parentId)
{

    try
    {
        /*try to assign the compositor*/
        this->scene = (SceneContainer*) pluginList->get(SceneContainer::getPluginName());
    }
    catch(std::runtime_error& e)
    {
    /* for some reasons, the list doesnt have the compositor */
        std::cerr << "ERROR: Cant find the SceneContainer,"
        << "needed for the SceneYobject yobject with id:"
        << id << ", "  << e.what() << "\n";
    }

    childs = new std::vector<std::shared_ptr<SceneYobject>>();
}

SceneYobject::SceneYobject(int id,
                         std::string name,
                          PluginList* pluginList)
                          : SceneYobject(id,0,pluginList)
{
    this->name = name;
    this->type = "Entity";
}


SceneYobject::~SceneYobject()
{
    
}

void SceneYobject::registerYobject(std::shared_ptr<SceneYobject> yobject)
{
    /*register yourself*/
    scene->addYobject(yobject);
}
void SceneYobject::unregisterYobject(std::shared_ptr<SceneYobject> yobject)
{
    scene->removeYobject(yobject);
}

 /*attach another scene node to this to notice 
          the propagated translations. see tranlsate()*/
void SceneYobject::attachChild(std::shared_ptr<SceneYobject> yobject)
{
    childs->push_back(yobject);
}

/*propagate down the translate function*/
void SceneYobject::translateChilds(int dx, int dy)
{

    /* update the position. maybe the where overwritten*/
    this->updatePosition(dx,dy);

    for (auto it = childs->begin();it != childs->end(); it++)
    {
            (*it)->translateChilds(dx,dy);
    } 

}