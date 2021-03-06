#include "TestPlugin.h"

/* to walking around*/
#include "WalkEvent.h"

/*set the globals*/
#include "InitGlobals.h"

//prototyp 
int grantAction(char* action);


/*signal the plugin was reloaded*/
int wasReloaded = 0;

/*the door status*/
int isDoorOpen = 0;


int HeyTentacle = 0;

int BernardIsInTheRoom = 0;


Start Event InitScene
{

    trigger StartScene
}

Event StartScene
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
        mouse trigger : CheckOpenDoor

    Character Tentacle
        position : 500, 300
        picture "standing": "../res/docstanding.png"
        display : "green tentacle"
        mouse trigger : CheckChoice


    Scene Object Clock
        position : 800, 200
        picture "right": "../res/clockRight.png"
        picture "middle": "../res/clockMiddle.png"
        picture "left": "../res/clockLeft.png"
        display: "clock"

     Scene Object TriggerZone
        position : 227, 0
        picture "right": "../res/closedDoorTiggerZone.png"


    int CharacterId = CharacterGetId(pluginList,"PurpursRoom");
    CharacterSetRenderPriority(pluginList,CharacterId,0);
    CharacterDeactivateCollider(pluginList,CharacterId);

    CharacterId = CharacterGetId(pluginList,"Door");
    CharacterDeactivateCollider(pluginList,CharacterId);

    /* walk collider should ignore this*/
    CharacterId = CharacterGetId(pluginList,"TriggerZone");
    CharacterDeactivateCollider(pluginList,CharacterId);

    /* close he Door*/
    Door set current picture to "closed"

    Segment Collider SegWallRight
        start position : 416, 217
        end position : 1023,299

    Segment Collider SegWallLeft
        start position : 447, 208
        end position : 22,364

    trigger Prolog
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

    wait for 2 s

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
    CharacterSetWalkCollider(pluginList,CharacterId,20,20,230);
    CharacterSetWalkAnimationFkt(pluginList,CharacterId,walkAnimation);
    CharacterSetDecideEnqueueActionFunction(pluginList,CharacterId,grantAction);

    Bernard walk to 400, 200

    /*close the door*/
    Door set current picture to "closed"

    BernardIsInTheRoom = 1;

    trigger WalkEvent,ClockTicking,CheckDoorCollision

}

Event ClockTicking
{
    Clock set current picture to "left"
    wait for 2 s
    Clock set current picture to "middle"
    wait for 2 s
    Clock set current picture to "right"
    wait for 2 s
    Clock set current picture to "middle"
    wait for 2 s

    trigger ClockTicking
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
        display "Hey Doc!!" if (!HeyTentacle) and trigger TentacleBernard
        //display "ein Test" if(1) and trigger Exit. TODO: trace this bug
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

    Bernard talks to Tentacle "Hey Doc! What's up?" 
        time : 4.0s 
        size : 30 
        color : 255, 255, 255

    Tentacle talks to Bernard "Hello Bernard. Just standing around" 
        time : 4.0s 
        size : 30 
        color : 0, 255, 0

    Tentacle talks to Bernard "Sometimes i'm bored" 
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
        if (!isDoorOpen)
            Door set current picture to "open"
        else
            Door set current picture to "closed" 

        isDoorOpen = !isDoorOpen;
    }
}

Event CheckDoorCollision
{

    int loop;
    loop = 1;

    while(loop)
    {
        int CharacterId = CharacterGetId(pluginList,"TriggerZone");
        if (isDoorOpen && CharacterCurrentPictureCollides(pluginList,CharacterId,"","WalkCollider"))
        {
            trigger InitScene2
            printf("Collides");
            loop = 0;
        }

        if (!(SuspendTaskUntilNextRound(pluginList,"CheckDoorCollision")))
        {
            /*got kill instruction. break*/
             RemoveTask(pluginList,"CheckDoorCollision");
             return;
        }

    }
   
}


int grantAction(char* action)
{

    printf("\ngrant action call\n");

    int grant = 1;

    // lock the player to prevent status changes
    int CharacterId = CharacterGetId(pluginList,"Bernard");
    CharacterLock(pluginList,CharacterId);
    
    char* status = CharacterGetStatus(pluginList,CharacterId);
    printf("status %s; action %s \n",status,action);

    if (strcmp(status,"None") == 0)
    {
        grant = 1;
    }
    else if (strcmp(status,"Walk") == 0)
    {
        //walk can be arborted with a choice
        if (strcmp(action,"Choice") == 0)
        {
            CharacterAbortCurrentActions(pluginList,CharacterId);
            grant = 1;
        }
        else
        {
            grant = 0;
        }

    }
    else if (strcmp(status,"Walk") != 0)
    {
        // the choice and other stuff can't get interrupted. deny all
        grant = 0;
    }

    CharacterUnlock(pluginList,CharacterId);

    return grant;
}



void reloadInit(void* _pluginList,void *_renderer)
{

    /* thats not good. we loaded the plugin again*/

    SceneFreeList(_pluginList);
    TriggerZoneFreeList(_pluginList);
    ColliderFreeList(_pluginList);
    CompositorFreeList(_pluginList);

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

    /*if i kill things here the waked up functions try to acess stuff before
      clean themself*/
}