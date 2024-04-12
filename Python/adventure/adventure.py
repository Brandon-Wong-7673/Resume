"""Brandon Wong
    sources: none"""
"""The structure of the program is simple. 
The player starts at the entrance to the castle. 
They are then asked what room they would like to visit. 
When they visit that room, a brief description of the room and what 
they found there is printed, and then they are asked to choose another 
room to visit next. If they player chooses to visit the exit, then the
game ends. Similarly, if the player finds the treasure in a room, the 
game ends. You may have as many rooms as you like, within the following
constraints:"""
import random


def printMap():
    """
    printmap
    input: none
    output: prints the known parts of the dungeon 
    """
    for line in map:
            print(line)
    print("\n")
def isDead(chance):
    """
    isDead
    input: the chance that the player will trigger a trap. (1 in input chance)
    output: True or False depending on if the random rolls a 1 or not ()
    """
    if (random.randint(1,7) == 1):
        return True
    return False

# empty var so that text doesnt pass by too quickly
empty = ""
# to keep track of what ending the player got
ending = 0
# to keep track of the room number (numbered from top to bottom left to right)
room = 9 
# makes sure the program doesnt think the player is conusly endering the same room
tempRoom = 9 
# var to see if chest has been opened and if items have been used (true means unopened/unused)(num = room)
chest4 = True
chest6 = True
chest8 = True
chest9 = True
gate7 = True
note = True
shield = True
dingus = False
boom = False
# var for each map segment 
map = [" __ ___ __ ____",
       "  _ _ __________ _ __ ",
       " ____ __________ ___ ",
       " __ _ __________ _ _ ",
       " _ __ __________ __ _ ",
       " _ __ __________ ___ __ ____",
       "  ___  ________  __  __  ________  __ ___  _|    |_  ____",
       " __ _ |        |________|        | ___ __ |        | _ __",
       " _  _ |         ________         | __  __ |        | __ _",
       " ___  |_      _| __ __  |_      _| _ _ __ |_      _|  _ _",
       " _ ____ |    | _ __ __ __ |    | ___ __ __  |    | __  __",
       " _  _  _|    |_ __ __ _  _|    |_  __ ___  _|    |_ __ __",
       "  ___ |        | ___ __ |        |________|        | ___ ",
       " __ _ |        | __  __ |   (P)   ________         | __ _",
       " _ __ |________| __  __ |_      _| __  __ |________| _  _",
       " _____  _____  _____  ___ |    | ___  _____  _____  _____",
       " _____  _____  _____   ____________   _____  _____  _____",
       " _____  _____  _______    ______    _______  _____  _____",
       " _____  _____  _____    _/      \_    _____  _____  _____",
       " _____  _____  _____   |          |   _____  _____  _____",
       " _____  _____  _____   |          |   _____  _____  _____",
       " _____  _____  _____   |          |   _____  _____  _____",
       " _____  _____  _____  _|__________|_  _____  _____  _____"
       ]

print("\n \n \n")
print("You have heard stories of a dungeon that contains treasure beyond the imagination.")
print("You have arived at this very dungeon and were lucky enough to buy a map that ")
print("of what has been exproded so far")
empty = input("[Enter anything to continue]: ") 
while (ending == 0):
    printMap()
    # random chance of death in every room but the starting one
    if (room != 3):
        deathChace = 7
    else: 
        # incress chance of death in 2nt from last room
        deathChace = 2
    if (isDead(deathChace) and (room != 9) ):
        # what happens if the deathChace = 1
        if(note and (chest9 == False)):
            print("Suddenly you hear a click in the floor, what ever is about to happen isn't good.")
            print("As feel the hallway rumbling you remember what was on the Cyptic Note.")
            print("You where berly able to tuck into the side of the wall before the bolder whent down ")
            print("the hallway. You doubt that the note will be usefull again\n")
            print("------ You Lost Cyptic Note ------")
            note = False
        elif(shield and (chest8 == False)):
            print("Suddenly you hear a click in the floor and a loud scraping sound from the walls.")
            print("Parts of the wall move revealing slits in the walls. You make a mad dash to the")
            print("next room but a axe swings out of the wall. You were able to use your shield")
            print("to deflect the axe. You managed to get out fine but you cant say the same for")
            print("shield. You doubt that the shield will be usefull again")
            print("------ You Lost Shield ------")
            shield = False
        else: 
            print("Suddenly you hear a click in the floor and you realised to late that there was no floor")
            print("under you anymore, only a pit of snakes.")
            break
    # descriptions of the rooms as you enter them
    if (room == 3):
        print("Entering the room you relize that this is the only room you have seen")
        print("with any furniture. Your guessing that any of the furniture in the other")
        print("rooms, broken or intact, where probably taken and pawned off.\n")
        print("and then there is the large door in front of you, all of your")
        print("instances are telling you that beond this door is the treasure")
        print("that you have been seeking\n")
        print("besides the large door in front of you there is also a door to the left\n")
    elif (room == 4):
        print("Entering the room you notice that it is not only undamaged, but ")
        print("extraordinary well matained. If you wern't in a ancient ruin you")
        print("could have sworn this that built within the last month. The walls")
        print("had gold echting of plaints and orgainic looking patterns. You ")
        print("realize that the weird texture on the walls in the previous rooms")
        print("was where the the gold echting used to be before the elements or")
        print("thieves took them away\n")
        print("But the thing that you where most intrested in was the large")
        print("quartz chest that had the same gold echting and lining as the walls\n")
        print("there is the open gate behind you and a doorway to your left\n")
    elif (room == 5):
        print("Entering the room you see that it is just a regular room with nothing in it,")
        print("but there is somthing unsettling that you cant put your finger on\n")
        print("there is a door behind you and one to the right of you\n")
    elif (room == 6):
        print("Entering the room you see that it is considerably more intact than the first room.")
        print("There is only a bit of rubble around you and the number of large cracks in the wall")
        print("can now be counted on two hands.")
        print("and are growing in the cracks in the stones. \n")
        print("the room has 2 doors. One behind you to the first room and another to the left of you\n")
        if (chest6):
            print("it seems there are still things unlooted in this room. For example the heavily rusted chest")
            print("on the far end of the room")
        else:
            print("the Only thing left in this room is the remnants of the chest you \"opened\"")
    elif (room == 7):
        print("Entering the room you see that it is only sightly decrepitated, the only strange thing in the")
        print("room is", end="")
        if (gate7):
            print("a gold gate blocking you from going forward\n")
            print("if it wern't for that gate you could go forward")
        else:
            print("the fake gold gate that you opened\n")
            print("you can go though the gate, into the room ahead of you")
        print("there is also the door behind you")
    elif (room == 8):
        print("Entering the room, only thing intresting about this room is that it is the only dead end that you")
        print("have seen seen so far and that there is a chest in the middle of it.\n")
        print("the only way to go is the door in front of you.")
    elif (room == 9):
        print("Entering the first room in the dungeon you see the grey stones have been heavily worn and chiped from")
        print("the element and other explorers. It seems that some of the flora form outside have snuck in")
        print("and are growing in the cracks in the stones. The walls them selfs seem to have a odd texture to them. \n")
        print("the room has 3 doors. One that leads to the exit behind you. One in front of you and one to the right of you\n")
        print("In the room its self there is",end=" ")
        if (chest9):
            print("a chest on the left of the room with a skeleton wearing a brown hat,\na tan shirt and a whip at it's side.")
        else:
            print("the empty chest you opened")
    elif (room == 10):
        print("Entering the room you see old paintings on the wall, disappointingly the pictures dont look all that expensive.")
        print("most of the paintings are of young people in there 20-30 with only a few paintings that look vaguely like the")
        print("landscape outside You guess that most of there value would be from its history or that fact that it was found")
        print("here, even then thepainting probably wouldn't fetch a high price. At least not high enough to justify coming here,")
        print("and definitely not enough to pay off any of the debt you have from the cost of the map and student loans\n")
        print("besides the paintings there is the door to your left leading back to the entrance and one in front of you.")
    # empty input so that the player can read more easily 
    empty = input("\n[Enter anything to continue]: ") 
    tempRoom = room
    # makes it so that the code above doesnt exicute if you didnt leave the room
    while (room == tempRoom):
        # what the player can do in each room
        if (room == 3):
            print("\n[ map, up , right ]\n")
        if (room == 4):
            print("\n[ map, down , left , chest ]\n")
        if (room == 5):
            print("\n[ map,", end="")
            if (boom):
                print(" up, ", end="")
            print(" down , right", end="")
            if ((chest4 == False) and (boom == False)):
                print(", bomb",end="")
            print(" ]\n")
        elif (room == 6):
            print("\n[ map, down , left , chest ]\n")
        elif (room == 7):
            if (gate7):
                 print("\n[ map, down, gate ]\n")
            else:
                print("\n[ map, up, down, gate ]\n")
        if (room == 8):
            print("\n[ map, up, chest ]\n")
        if (room == 9):
            print("\n[ map, up , right , chest , exit ]\n")
        if (room == 10):
            print("\n[ map, up , left ]\n")
        chose = input("What would you like to do?: ")
        print("\n")
        # what happens when the player does somthing
        if(chose == "map"):
            for line in map:
                print(line)
        elif (room == 3):
            if(chose == "up"):
                room = 1
                ending = 3
            if(chose == "right"):
                print("You went through the right door")
                room = 4
        elif (room == 4):
            if(chose  == "chest"):
                if(chest4):
                    print("You go over to the quartz chest. You imagine that the chest would sell for a small fortune")
                    print("if you could carry it out of the dungeon. which you do try before realizing that is probably")
                    print("weighed more then you do. Not wanting to break the chest you pull out a lockpick...\n ")
                    print("You had a lockpick this whole time!?", end="")
                    if (dingus):
                        print("Why didn't you use it on the gate?", end="")
                    print("Why didn't you use it on the rusted chest? ")
                    print("Were you so lazy that you chose to break it insted of picking it open or were you so spiteful")
                    print("towards archaeologist that you broke it despite knowing there was a way to preserve it.\n")
                    print("either way you pick open the chest and pull out what is undoubtly a bomb. I hope you blow")
                    print("your self up with it you monster.\n")
                    print("------ You Got Bomb ------")
                    chest4 = False
                else:
                    print("You make a metal note to hirer a few people to carry the quartz chest outside.")
            if(chose == "left"):
                print("You went through the left door")
                room = 3
            if(chose == "down"):
                print("you whent back through the gate")
                room = 7
        elif (room == 5):
            if(chose  == "bomb" and (chest4 == False)):
                print("this wall has botherd you since you first came into the room. It might be becuse the wall")
                print("is slightly lighter then the other walls. It might be becuse the cracks in the wall look strange")
                print("to you. What ever it was that botherd you it wont exist in the next few seconds. You light the fuse")
                print("on the bomb, chuck it, and duck into the hallway... \n")
                print("...\n")
                print("...\n")
                print("Maybe the bomb was a dud? You are about to peek around the corrner wh-\n")
                print("BOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOMMMMMMMMMMMMMMMMMMM\n")
                print("------ Your Map Has Been Updated ------\n")
                map[8] =  "  _ _  ________  _ __ _  _|    |_  __  __  ________  _ __ "
                map[9] =  "  ___ |        | ___ __ |        |________|        | _  _ "
                map[10] = " __ _ |        | _ _ __ |         ________         | __ __"
                map[11] = " _ __ |_      _| __ ___ |________| _ ____ |_      _| _ __ "
                map[12] = " _ __   |    |  ____ __ ___ ____ _ _____ __ |    | _ __ __"
                map[13] = "  ___  _|    |_  __  __  ________  __ ___  _|    |_  ____"
                boom = True
                empty = input("\n[Enter anything to continue]: \n") 
                printMap()
            elif ((chose == "up") and (boom)):
                print("you go forward into the hole you made.")
                room = 2
                ending = 4
            elif(chose  == "down"):
                print("You went through the door behind you")
                room = 8
            elif(chose  == "right"):
                print("You went through the right door")
                room = 6
        elif (room == 6):
            if (chose  == "chest"):
                if(chest6):
                    print("You go over to the rusted chest. Luckly you brought a crowbar with you just for situations")
                    print("like this. You carfuly and gently bash the chest with the crowbar, sending skidding across")
                    print("the room. After a few minues of your \"carful\" work, the chest now looks like a jigsaw puzzle")
                    print("that a pet got to...         ")
                    print("and then thrown into a wood chiper. But going through what was the chest and fragmants of ")
                    print("artifacts that would make any archaeologist weep at the sight of what you have done, you found")
                    print("a gold key\n")
                    print("------ You Got Gold Key -----")
                    chest6 = False
                else:
                    print("You stand over the what is left of the chest, if any archaeologist ever found out what you did,")
                    print("you will surely be baned from every museum in the world. I hope you are proud of yourself.")
            elif (chose  == "down"):
                print("You head back to the entrance")
                room = 9
            elif (chose  == "left"):
                print("You head into the left door")
                room = 5
        elif (room == 7):
            if(chose  == "gate"):
                if(chest6 == False and gate7):
                    print("You walk over to the gold gate and take out the gold key to unlock it. While doing so you realized")
                    print("that both the gate and the key whern't acualy gold but just painted to look like there gold.")
                    print("You where secretly hoping to sell both the key and the gate for a good sum but all your left with")
                    print("now is disappointment and a fake gold key. You toss the key aside.")
                    print("You doubt that the key will be usefull again...        in both a literal and montary sence\n")
                    print("------ You Lost Fake Gold Key ------\n")
                    print("------ Your Map Has Been Updated ------\n")
                    map.insert(0, "  _____ _____ ______  ______________  ______ _____ _____")
                    map.insert(1, " /____ __ ____ ____ __ _____ __ _ ____ ____ ___ ___ ____\\")
                    map.insert(2, " ___ ___ ___ _ __ _   ______________   __ _____ _ _______")
                    map.insert(3, " __ _ _ ___ __ _____ |              |   ____ _ _____ __ _")
                    map.insert(4, " _ ___ _ __ __ ____  |              |  _  ___ __ _ ___ __")
                    map.insert(5, " _ __ ____ ____ ___  |              |   __ ___ _____ ____")
                    map.insert(6, " _  _ ___  _ ___ __  |____      ____|  ___  _ __ ___ __ _")
                    map[7] =  " __ ___ __ ____ __ ___ __ |    | __ ____ ___ __ ____ _ __"
                    map[8] =  "  _ _ __________ _ __ _  _|    |_  __  __  ________  _ __ "
                    map[9] =  "  ___ __________ ___ __ |        |________|        | _  _ "
                    map[10] = " __ _ __________ _ _ __ |         ________         | __ __"
                    map[11] = " _ __ __________ __ ___ |________| _ ____ |_      _| _ __ "
                    map[12] = " _ __ __________ ___ __ ___ ____ _ _____ __ |    | _ __ __"
                    gate7 = False
                    empty = input("\n[Enter anything to continue]: \n") 
                    printMap()
                elif(chest6 == False): 
                    print("it's the fake gold gate that you opened and it leads to a room in front of you. But more importantly")
                    print("that gate lead to the disappointment that hangs in your heart")
                else:
                    print("To open the gold gate you will probably need a key that is, helpfully, the same color as the gate")
            if(chose == "up"):
                if(gate7):
                    print("You slowly walk up to and hit you head on the gate. This causes you to fall down flat on you butt\n")
                    print("------ HP -1 ------\n")
                    print("Seriously what do not understand about \"blocking you from going forward\" you dingus")
                    dingus = True
                else:
                    print("You went through the door in front of you.")
                    room = 4
            if(chose == "down"):
                print("You went through the door behind you")
                room = 10
        elif (room == 8):
            if(chose  == "chest"):
                if(chest8):
                    print("You go to the chest in the middle of the room, to your surprise the chest is both easy to open")
                    print("and has somthing in it. The somthing in question is a shield which would not be the first thing")
                    print("you would put in a chest, you would probably put alot of gold, treasure and a note saying how")
                    print("clever and handsome/beautiful they are.\n")
                    print("------ You Got Shield ------")
                    chest8 = False
                else:
                    print("though the chest is empty it fills your with joy knowing that there are chests out there that")
                    print("aren't a disappointment or a pain to open.")
            elif(chose == "up"):
                print("You went through the door in front of you.")
                room = 5
        elif (room == 9):
            if (chose  == "chest"):
                if(chest9):
                    print("You go over to the left wall and open the chest.")
                    print("it was empty...") 
                    print("You should have expected that it would be empty, this is the first room after all.") 
                    print("But now that you are closer to the skeleton you see that it is holding a note ")
                    print("You carfully take the note from the skeleton and read it. It seems to be a cryptic ")
                    print("warning about a trap ahead.\n") 
                    print("------ You Got Cyptic Note -----")
                    chest9 = False
                else:
                    print("The chest was alredy empty before you got to it. Are you expeting somone to respawn in there?")
            elif (chose  == "exit"):
                room = 0
                if (chose  == "exit" and (chest9 == False) and (note == False)):
                    ending = 2
                else:
                    ending = 1
            if(chose  == "up"):
                print("You went through the door in front of you.")
                room = 6
            elif(chose  == "right"):
                print("You went through the right door.")
                room = 10
        elif (room == 10):
            if(chose  == "up"):
                print("You went through the door in front of you.")
                room = 7
            if(chose  == "left"):
                print("You head into the left door")
                room = 9
        # updates (P) to where player is
        if (room == 1):
            map[5] = " _ __ ____ ____ ___  |     (P)      |   __ ___ _____ ____"
            map[10] = " __ _ __________ _ _ __ |         ________         | __ __"
        if (room == 2):
            map[10] = " __ _ |   (P)  | _ _ __ |         ________         | __ __"
            map[len(map)-15] = "__  _ |         ________         | __  __ |        | __ _"
        if (room == 3):
            map[10] = " __ _ __________ _ _ __ |    (P)  ________         | __ __"
        if (room == 4):
            map[10] = " __ _ __________ _ _ __ |         ________    (P)  | __ __"
            map[len(map)-15] = "__  _ |         ________         | __  __ |        | __ _"
        if (room == 5):
            map[len(map)-15] = "__  _ |   (P)   ________         | __  __ |        | __ _"
            map[len(map)-10] = "___ _ |        | __  __ |         ________         | __ _"
        if (room == 6):
            map[len(map)-15] = "__  _ |         ________    (P)  | __  __ |        | __ _"
            map[len(map)-10] = "___ _ |        | __  __ |         ________         | __ _"
        if (room == 7):
            if(len(map) != 23):
                map[10] = " __ _ __________ _ _ __ |         ________         | __ __"
            map[len(map)-15] = "__  _ |         ________         | __  __ |   (P)  | __ _"
            map[len(map)-10] = "___ _ |        | __  __ |         ________         | __ _"
        elif (room == 8):
            map[len(map)-15] = "__  _ |         ________         | __  __ |        | __ _"
            map[len(map)-10] = "___ _ |   (P)  | __  __ |         ________         | __ _"
        elif (room == 9):
            map[len(map)-15] = "__  _ |         ________         | __  __ |        | __ _"
            map[len(map)-10] = "___ _ |        | __  __ |   (P)   ________         | __ _"
        elif (room == 10):
            map[len(map)-15] = "__  _ |         ________         | __  __ |        | __ _"
            map[len(map)-10] = "___ _ |        | __  __ |         ________    (P)  | __ _"
            
print("\n")
if (ending == 0):
    print("------ GAME OVER ------")
elif (ending == 1):
    print("You chose to run away from the dungeon like a coward. The map of the dungeon you bought")
    print("wasn't cheep, the person who made the map died while doing so and the person who ")
    print("retreved the map got a arrow in the knee and had to retire. The cost of the map plus")
    print("your student loans from adventuring school ment that you and your famly would be")
    print("financially crippled for generations")
    print("\n\n------ ENDING(1/4): DEBT ------ ")
elif (ending == 2):
    print("You chose to run away from the dungeon with your life. The map of the dungeon you bought")
    print("wasn't cheep, the person who made the map died while doing so and the person who retreved")
    print("the map got a arrow in the knee and had to retire. Luckly your near death experience")
    print("insipered you to make a novel that was later made into a play. Though when you heard")
    print("somone was able to get the dungeon's treasure, you couldnt help but be envious. You where")
    print("able to live out the rest of your days off of royalties and thoughts of what could have been")
    print("\n\n------ ENDING(2/4): THE NEXT JRR ------ ")
elif (ending == 3):
    print("You did it. You made it through all the traps, gates, and disappointments. You open ")
    print("the door to mountain of riches. You are sure that this is enough money to last 2, no maybe")
    print("4 whole life times. Which would make you one of the ritches people in the kingdom before")
    print("you lost half of it due to taxes. You are still very ritch but not as ritch as you first")
    print("thought. You were still able to live a good life off of the treasure, but somthing has been")
    print("bugging you about the dungeon for decades. You haven't been able to put your finger on it")
    print("but you are sure there is somthing more it there, this was the last thought you had before")
    print("you passed on...")
    print("\n\n------ ENDING(3/4): UNFINISHED BUSINESS ------ ")
elif (ending == 4):
    print("What you found on the other side was more then just tressure, it was miracles. A horn that")
    print("that endlessly spewed out food, a helmet that made the wearer invisible, and a fountan that")
    print("made people younger. But one thing caught your eye, a worn, yellowing and crubbling note")
    print("reading the note you didnt quite understand what it ment, but it filled you with pride.")
    print("The note said:")
    print("\n\n------ ENDING(4/4): THANK YOU FOR PLAYING! ------ ")
print("\n")