#include "MessageYobject.h"
#include <stdexcept>
#include <limits>

MessageYobject::MessageYobject(int id,
                               int parentId,
                               std::string text,
                               int characterId,
                               PluginList* pluginList)
                                : RenderableYobject(id,parentId,pluginList),
                                  SceneYobject(id,parentId,pluginList)
{
    GlobalSettings* globalSettings = nullptr;
    try
    {
        /*load the defaults.*/
        globalSettings = (GlobalSettings*) pluginList->get(GlobalSettings::getPluginName());
    }
    catch(std::runtime_error& e)
    {
        std::cerr <<"ERROR: Cant find the global Settings, subtask id: "<< id 
        << ", "  << e.what() << "\n";
    }


    union SettingsValue defaultPos = globalSettings->getSetting("DefaultPosition");
    union SettingsValue defaultSize = globalSettings->getSetting("DefaultSize");
    union SettingsValue defaultColor = globalSettings->getSetting("DefaultColor");
    union SettingsValue defaultFontPath = globalSettings->getSetting("DefaultFont");

    /*transform the color to a sdl color*/
    SDL_Color sdlColor;
    sdlColor.r = defaultColor.colorValue.r;
    sdlColor.g = defaultColor.colorValue.g;
    sdlColor.b = defaultColor.colorValue.b;

    /*build the message, the texture will be created later by calling InitRessources()*/
    this->message = new Message(text,
                                defaultFontPath.stringValue,
                                defaultPos.positionValue.posX,
                                defaultPos.positionValue.posY,
                                defaultSize.intValue,
                                sdlColor,
                                this->renderer /*init by rederableYobject*/
                                );

    owner = nullptr;

    if (characterId > -1)
    {
        try
        {
            std::shared_ptr<Yobject> charYobject = scene->getYobject(characterId);

            this->owner = std::static_pointer_cast<Character>(charYobject);
        }
        catch(std::runtime_error& e)
        {
            std::cerr <<"ERROR: Cant find the Scene Editor, subtask id: "<< id 
            << ", "  << e.what() << "\n";
        }

        /* get the offset for the message. TODO: calc this with char size*/
        Position p = owner->getPosition();
        p.posY -= 50;
        message->setPosition(p);

    }
    
    fixedTextPosition = false;
    hasInitializedRessources = false;

    setRenderPriority(std::numeric_limits<double>::max());

}


MessageYobject::~MessageYobject()
{
    /*signal the destruction of the message*/
    /*should be killed now... after the deletion of the message 
      you cant call the function*/
    signalFreeRessourcesNow();

    delete message;
}

void MessageYobject::initRessources()
{
    message->createTexture();
    hasInitializedRessources = true;
}

void MessageYobject::freeRessources()
{
    message->destroyTexture();
    hasInitializedRessources = false;
}

void MessageYobject::getSize(int & width, int & height)
{
    /*return -1,-1 if it has no texture*/
    message->getSize(width,height);
}


void MessageYobject::render()
{

    /* display the text over the owner */
    /* TODO : clac an offset */
    //if ((owner) && (!this->fixedTextPosition))
    //{
    //    Position p = owner->getPosition();
    //    p.posY -= 50;
    //    message->setPosition(p);
    //}
    
    message->render();
}

void MessageYobject::setPosition(Position pos)
{
    this->message->setPosition(pos);
}

void MessageYobject::setPosition(int posX, int posY)
{
    this->message->setPosition(posX, posY);
}

Position MessageYobject::getPosition()
{
    return this->message->getPosition();
}

void MessageYobject::setFontPath(std::string fontPath)
{
    this->message->setFontPath(fontPath);
    /* need a new build of the message*/
    if (hasInitializedRessources) signalInitRessourcesNow();
}

void MessageYobject::setFontSize(int fontSize)
{
    this->message->setFontSize(fontSize);
    /* need a new build of the message*/
    if (hasInitializedRessources) signalInitRessourcesNow();
}

void MessageYobject::setFixTextPosition(bool fixedTextPosition)
{
    this->fixedTextPosition = fixedTextPosition;
}

void MessageYobject::setColor(int r, int g, int b)
{
    this->message->setColor(r,g,b);
}

void MessageYobject::setColor(SDL_Color color)
{
    this->message->setColor(color);
    /* need a new build of the message*/
    if (hasInitializedRessources) signalInitRessourcesNow();
}


void MessageYobject::registerYobject(std::shared_ptr<MessageYobject> yobject)
{
    /*TODO:WORKAROUND */
    RenderableYobject::registerYobject(std::static_pointer_cast<RenderableYobject>(yobject));
    SceneYobject::registerYobject(std::static_pointer_cast<SceneYobject>(yobject));
    /*dock yourself to the character*/
    if(owner)
        owner->attachChild(std::static_pointer_cast<SceneYobject>(yobject));
}

void MessageYobject::unregisterYobject(std::shared_ptr<MessageYobject> yobject)
{
    RenderableYobject::unregisterYobject(std::static_pointer_cast<RenderableYobject>(yobject));
    SceneYobject::unregisterYobject(std::static_pointer_cast<SceneYobject>(yobject));
    /*unddock yourself from the character*/
    if(owner)
        owner->detachChild(std::static_pointer_cast<SceneYobject>(yobject));
}

void MessageYobject::updatePosition(int dx, int dy)
{

    if (!this->fixedTextPosition)
    {
        Position p = message->getPosition();
        p.posX += dx;
        p.posY += dy;
        message->setPosition(p);
    }

}