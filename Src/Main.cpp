#include "Main.h"

using namespace ait;
Window *app;

int main()
{
	app = new Window();
	app->Init(APP_UID);
	app->SetBackgroundColor(gGray);
	ClientInit();

	while (!app->GetQuit())
	{
		app->Update();

		if (app->GetWindow()->GetEvent(*app->GetInput()->GetEvent()))
		{
			if (app->GetInput()->GetEvent()->Type == sf::Event::Closed)
				app->SetQuit(true);
			else if (app->GetInput()->GetKeyState(GK_Escape, KEY_DOWN))
				app->SetQuit(true);
		}
	}

	app->Shutdown();

	return EXIT_SUCCESS;
}


bool ait::ClientInit()
{
	return false;
}


void ait::ClientLoop()
{
}