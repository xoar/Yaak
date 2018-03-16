#include "TestPlugin.h"

/* to walking around*/
#include "WalkEvent.h"

/*set the globals*/
#include "InitGlobals.h"


/*signal the plugin was reloaded*/
int wasReloaded = 0;

/*the door status*/
int isDoorOpen = 0;


int HeyTentacle = 0;

int BernardIsInTheRoom = 0;



Start Event InitScene
{

    InitGlobals();

    Scene Object PurpursRoom
        picture "standing":  "../res/purpurRoom2.png"
        position : 0, 0

    Scene Object Door
        position : 227, 0
        picture "open": "../res/openDoor.png"
        picture "closed": "../res/closedDoor.png"
        display : "Door"
        trigger : CheckOpenDoor

    Character Tentacle
        position : 500, 300
        picture "standing": "../res/docstanding.png"
        display : "green tentacle"
        trigger : CheckChoice

    /* close he Door*/
    Door set current picture to "closed"

    Segment Collider SegWallRight
        start position : 416, 217
        end position : 1023,299

    Segment Collider SegWallLeft
        start position : 447, 208
        end position : 22,364

    if (!wasReloaded) 
    {
        trigger Prolog
    }
    else
    {
        trigger IntroduceBernard
    }
}


Event Prolog
{

    System talks "*Prolog ... bla bla bla ... some previous history ...*" 
        time : 4.0s 
        size : 50 
        color : 255, 144, 0


    System talks "Bla bla bla.... let's start!" 
        time : 4.0s 
        size : 50 
        color : 255, 144, 0

    /*wait on an input*/
    wait on left mouse click

    /*now let bernard come in*/
    trigger IntroduceBernard

}

Event IntroduceBernard
{

    /* open the Door*/
    Door set current picture to "open"

    /*create Bernard*/
    Character Bernard
        picture "standing right" : "../res/C1WR2.png"
        picture "standing left" : "../res/C1WL2.png"

        position : 300, 50

        animation "walking right":  "../res/C1WR1.png",
                                    "../res/C1WR2.png",
                                    "../res/C1WR3.png",
                                    "../res/C1WR2.png"

        animation "walking left": "../res/C1WL1.png",
                                  "../res/C1WL2.png",
                                  "../res/C1WL3.png",
                                  "../res/C1WL2.png"

        animation "walking up": "../res/C1WU1.png",
                                "../res/C1WU2.png",
                                "../res/C1WU3.png",
                                "../res/C1WU2.png"
                                
        animation "walking down": "../res/C1WD1.png",
                                  "../res/C1WD2.png",
                                  "../res/C1WD3.png",
                                  "../res/C1WD2.png"

    /*add a fix collider for bernard*/
    int CharacterId = CharacterGetId(pluginList,"Bernard");
    CharacterSetCollider(pluginList,CharacterId,20,20);
    CharacterSetWalkAnimationFkt(pluginList,CharacterId,walkAnimation);

    Bernard walk to 400, 200

    /*close the door*/
    Door set current picture to "closed"

    BernardIsInTheRoom = 1;

    trigger WalkEvent

}



Event CheckChoice
{
    /* check if the left mouse was clicked*/
    GameEvents events = EventSystemGetCurrentEvents(pluginList);

    if (events.leftMouseButtonPressed && BernardIsInTheRoom)
    {
        trigger ChoiceGreenTentacle
    }



}

Event ChoiceGreenTentacle
{
    Choice Bernard
        display "Exit"         if (1)            and trigger Exit
        display "Hey Tentacle" if (!HeyTentacle) and trigger TentacleBernard
}

Event Exit
{

    Bernard talks "I'm outta here!" 
        time : 4.0s 
        size : 50 
        color : 255, 255, 255

}


Event TentacleBernard
{

    HeyTentacle = 1;

    Bernard talks to Tentacle "Hey green tentacle! What's up" 
        time : 4.0s 
        size : 30 
        color : 255, 255, 255

    Tentacle talks to Bernard "Hello Bernard. Just standing around" 
        time : 4.0s 
        size : 30 
        color : 0, 255, 0

    Tentacle talks to Bernard "sometimes i'm bored" 
        time : 4.0s 
        size : 30 
        color : 0, 255, 0

    trigger ChoiceGreenTentacle
}


Event CheckOpenDoor
{
    /*TODO: why isnt it a error to left this line???*/
    GameEvents events = EventSystemGetCurrentEvents(pluginList);

    if (events.rightMouseButtonPressed)
    {
        trigger OpenDoor
    }
}


Event OpenDoor
{

    if (isDoorOpen)
    {
        trigger InitScene2
    }
    else
       Door set current picture to "open"

    isDoorOpen = !isDoorOpen;
}





void reloadInit(void* _pluginList,void *_renderer)
{

    buildRefs(_pluginList,_renderer);

    wasReloaded = 1;

    AddTaskForNextRound(pluginList,"InitScene", &InitScene );
}

void signalPluginReload()
{
    /** kill all stuff*/
    SceneFreeList(pluginList);
    TriggerZoneFreeList(pluginList);
    ColliderFreeList(pluginList);
    CompositorFreeList(pluginList);
}