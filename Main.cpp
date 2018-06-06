#include "Main.h"

void help()
{
	screen.setCursorPure(0, 30);
	cout << "Movement on hex grid:";
	screen.setCursorPure(1, 30);
	cout << " W E";
	screen.setCursorPure(2, 30);
	cout << "A   D";
	screen.setCursorPure(3, 30);
	cout << " Z X";
	screen.setCursorPure(4, 30);
	cout << "Characters '0'-'9' to place a new number.";
	screen.setCursorPure(5, 30);
	cout << " Space to pick a number or drop from 1-slot inventory.";
	screen.setCursorPure(6, 30);
	cout << "Character '-' to remove a number.";
	screen.setCursorPure(7, 30);
	cout << " Character '=' to undo last command.";
	screen.setCursorPure(8, 30);
	cout << "Character 'x' means free inventory slot, '+' is full.";
	screen.setCursorPure(9, 30);
	cout << " Numbers stack and only last dropped is visible.";
	screen.setCursorPure(10, 30);
	cout << "ESC to quit, please do not use x on upper right corner";
	screen.setCursorPure(0, 0);
	
}


int main()
{
	Player player('x', 0, 4, Hexes);
	char character;
	ICommand* movePlayer;
	ICommand* placePlayerInventory = new placeEntity(&player, &screen, Hexes);
	ICommand* pickPlayerInventory = new pickEntity(&player, &screen, Hexes);
	ICommand* createNumber;
	ICommand* removeNumber;

	help();
	screen.draw(Hexes);
	vector<Entity*> listOfEntities;
	
	while (1)
	{
		int x = player.getX();
		int y = player.getY();
		if (_kbhit())
		{
			character = _getch();
			switch (character)
			{
			case 'd':
			case '\'':
				movePlayer = new moveEntity(&player, E, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 'e':
			case '[':
				movePlayer = new moveEntity(&player, NE, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 'w':
			case 'p':
				movePlayer = new moveEntity(&player, NW, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 'a':
			case 'l':
				movePlayer = new moveEntity(&player, W, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 'z':
			case '.':
				movePlayer = new moveEntity(&player, SW, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 'x':
			case '/':
				movePlayer = new moveEntity(&player, SE, &screen, Hexes);
				movePlayer->Execute();
				break;
			case 0:
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				Hexes.PopHexContent(x, y);
				{
					createNumber = new createEntity(listOfEntities, character, x, y);
					createNumber->Execute();
				}
				Hexes.PushHexContent(x, y, &player);
				break;
			case '=':
				if (eventLog.size() > 0)
					eventLog[eventLog.size() - 1]->Undo();
				break;
			case '-':
				if (Hexes.Size(x, y) > 2)
				{
					Entity *w = Hexes.GetContent(x, y, Hexes.Size(x, y) - 2);
					removeNumber = new removeEntity(listOfEntities, w->getSprite(), x, y);
					removeNumber->Execute();
				}
				break;
			case ' ':
				Hexes.PopHexContent(x, y);
				if (player.HoldedObject())
				{
					placePlayerInventory->Execute();
				}
				else if (Hexes.Size(x, y) > 1)
				{
					pickPlayerInventory->Execute();
				}
				Hexes.PushHexContent(x, y, &player);
				break;
			case 27:
			{
				for (size_t j = 0; j < listOfEntities.size(); j++)
				{
					delete listOfEntities[j];
				}

				while (eventLog.size() > 0)
				{
					eventLog[eventLog.size() - 1]->Undo();
				}
				delete	placePlayerInventory;
				delete	pickPlayerInventory;
				return 0;
			}
			break;

			}
			screen.ShowTop(x, y);
		}

	}

}