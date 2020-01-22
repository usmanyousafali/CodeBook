#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

void make_inaplayers(CircleShape& inaplayer, float inaplayerX, float inaplayerY)
{
	inaplayer.setRadius(20);
	inaplayer.setFillColor(Color::Green);
	inaplayer.setPosition(Vector2f(inaplayerX, inaplayerY));
}

void make_oppplayers(CircleShape& oppplayer, float oppplayerX, float oppplayerY)
{
	oppplayer.setRadius(20);
	oppplayer.setFillColor(Color::Red);
	oppplayer.setPosition(Vector2f(oppplayerX, oppplayerY));
}

void goal_points_system(int& points_by_opp_int, Text& points_by_opp, int& goal_by_opp_int, Text& goal_by_opp)
{
	points_by_opp_int++;
	if (points_by_opp_int >= 3)
	{
		points_by_opp_int = 0;
		points_by_opp.setString(to_string(points_by_opp_int));
		goal_by_opp_int++;
		goal_by_opp.setString(to_string(goal_by_opp_int));
	}
	else
	{
		points_by_opp.setString(to_string(points_by_opp_int));
	}
}

int main()
{
	RenderWindow window(VideoMode::getDesktopMode(), "Inazuma Eleven", Style::Fullscreen);
	window.setFramerateLimit(60);

restart_again:
	float boundupY = 100; float bounddownY = 700;
	float poleY1 = 250; float poleY2 = 550;
	Vertex middleline[] = { Vertex(Vector2f((window.getSize().x / 2), boundupY)), Vertex(Vector2f((window.getSize().x / 2), bounddownY)) };
	Vertex boundup[] = { Vertex(Vector2f(0.f, boundupY)), Vertex(Vector2f(window.getSize().x, boundupY)) };
	Vertex bounddown[] = { Vertex(Vector2f(0.f, bounddownY)), Vertex(Vector2f(window.getSize().x, bounddownY)) };
	Vertex poleopp[] = { Vertex(Vector2f(10.f, poleY1)), Vertex(Vector2f(10.f, poleY2)) };
	Vertex poleplay[] = { Vertex(Vector2f(window.getSize().x - 10.f, poleY1)), Vertex(Vector2f(window.getSize().x - 10.f, poleY2)) };

	int goal_by_opp_int = 0;
	int goal_by_ina_int = 0;
	int points_by_opp_int = 0;

	Font font;
	font.loadFromFile("Roboto.ttf");

	Text goal_by_ina;
	goal_by_ina.setFont(font);
	goal_by_ina.setCharacterSize(100);
	goal_by_ina.setFillColor(Color::White);
	goal_by_ina.setPosition(Vector2f(window.getSize().x - 60, -10));
	goal_by_ina.setString(to_string(goal_by_ina_int));

	Text points_by_opp;
	points_by_opp.setFont(font);
	points_by_opp.setCharacterSize(50);
	points_by_opp.setFillColor(Color::White);
	points_by_opp.setPosition(Vector2f(0, 0));
	points_by_opp.setString(to_string(points_by_opp_int));

	Text goal_by_opp;
	goal_by_opp.setFont(font);
	goal_by_opp.setCharacterSize(100);
	goal_by_opp.setFillColor(Color::White);
	goal_by_opp.setPosition(Vector2f(30, -10));
	goal_by_opp.setString(to_string(goal_by_opp_int));

	Text winner_text;
	winner_text.setFont(font);
	winner_text.setCharacterSize(50);
	winner_text.setFillColor(Color::White);
	winner_text.setPosition(Vector2f((window.getSize().x / 2) - 100, bounddownY + 20));

	Clock timer;

	Text timer_text;
	timer_text.setFont(font);
	timer_text.setCharacterSize(50);
	timer_text.setFillColor(Color::White);
	timer_text.setPosition(Vector2f((window.getSize().x / 2) - 20, 10));

restart:
	CircleShape goalkeeperopp;
	goalkeeperopp.setRadius(20);
	goalkeeperopp.setFillColor(Color::Red);
	goalkeeperopp.setPosition(Vector2f(20.f, poleY1));

	CircleShape goalkeeperplay;
	goalkeeperplay.setRadius(20);
	goalkeeperplay.setFillColor(Color::Green);
	goalkeeperplay.setPosition(Vector2f((window.getSize().x - (2 * goalkeeperopp.getRadius())) - 20.f, poleY2 - (2 * goalkeeperopp.getRadius())));

	CircleShape football;
	football.setRadius(10);
	football.setFillColor(Color::Yellow);

	CircleShape inaplayer[10];
	string inaplayer_active[10] = { "Green", "Green", "Green", "Green", "Green", "Green", "Green", "Green", "Green", "Green" };
	int make_ina_active = 0;
	double inaplayer_D1, inaplayer_D2, inaplayer_D[10];
	make_inaplayers(inaplayer[0], ((window.getSize().x / 2) + 50), ((boundupY + bounddownY) / 2) - 20);
	make_inaplayers(inaplayer[1], ((window.getSize().x / 2) + 20), (inaplayer[0].getPosition().y - 150));
	make_inaplayers(inaplayer[2], ((window.getSize().x / 2) + 20), (inaplayer[0].getPosition().y + 150));
	make_inaplayers(inaplayer[3], ((window.getSize().x / 2) + 300), (boundupY + 50));
	make_inaplayers(inaplayer[4], ((window.getSize().x / 2) + 300), (((inaplayer[0].getPosition().y) + (inaplayer[1].getPosition().y + 20)) / 2));
	make_inaplayers(inaplayer[5], ((window.getSize().x / 2) + 300), (((inaplayer[0].getPosition().y) + (inaplayer[2].getPosition().y + 20)) / 2));
	make_inaplayers(inaplayer[6], ((window.getSize().x / 2) + 300), (bounddownY - 100));
	make_inaplayers(inaplayer[7], ((window.getSize().x / 2) + 600), ((boundupY + bounddownY) / 2) - 20);
	make_inaplayers(inaplayer[8], ((window.getSize().x / 2) + 600), (inaplayer[7].getPosition().y - 150));
	make_inaplayers(inaplayer[9], ((window.getSize().x / 2) + 600), (inaplayer[7].getPosition().y + 150));
	inaplayer[0].setFillColor(Color::Blue);
	inaplayer_active[0] = "Blue";

	CircleShape oppplayer[10];
	make_oppplayers(oppplayer[0], ((window.getSize().x / 2) - 100), ((boundupY + bounddownY) / 2) - 20);
	make_oppplayers(oppplayer[1], ((window.getSize().x / 2) - 60), (oppplayer[0].getPosition().y - 150));
	make_oppplayers(oppplayer[2], ((window.getSize().x / 2) - 60), (oppplayer[0].getPosition().y + 150));
	make_oppplayers(oppplayer[3], ((window.getSize().x / 2) - 250), (oppplayer[0].getPosition().y - 150));
	make_oppplayers(oppplayer[4], ((window.getSize().x / 2) - 250), (oppplayer[0].getPosition().y + 150));
	make_oppplayers(oppplayer[5], ((window.getSize().x / 2) - 400), ((boundupY + bounddownY) / 2) - 20);
	make_oppplayers(oppplayer[6], ((window.getSize().x / 2) - 600), (boundupY + 50));
	make_oppplayers(oppplayer[7], ((window.getSize().x / 2) - 600), (((oppplayer[0].getPosition().y) + (oppplayer[1].getPosition().y + 20)) / 2));
	make_oppplayers(oppplayer[8], ((window.getSize().x / 2) - 600), (((oppplayer[0].getPosition().y) + (oppplayer[2].getPosition().y + 20)) / 2));
	make_oppplayers(oppplayer[9], ((window.getSize().x / 2) - 600), (bounddownY - 100));

	bool football_check = false, football_check_goal = false;
	bool oppplayer_tray2 = false, oppplayer_tray3 = false, oppplayer_tray4 = false;
	bool game_start = true;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::R && timer.getElapsedTime().asSeconds() >= 180)
				goto restart_again;
		}

		timer_text.setString(to_string(static_cast<int>(timer.getElapsedTime().asSeconds())));
		if (timer.getElapsedTime().asSeconds() >= 180)
		{
			game_start = false;
			if (goal_by_ina_int > goal_by_opp_int)
			{
				winner_text.setString("You Win! :)");
			}
			else if (goal_by_ina_int < goal_by_opp_int)
			{
				winner_text.setString("You Lose! :(");
			}
			else if (goal_by_ina_int == goal_by_opp_int)
			{
				if (points_by_opp_int > 0)
				{
					winner_text.setString("You Lose! :(");
				}
				else
				{
					winner_text.setString("Match Draw! :-");
				}
			}
		}


		static int goalkeeperopp_dir = 2;
		if (goalkeeperopp.getPosition().y <= poleY1)
			goalkeeperopp_dir = 1;
		if ((goalkeeperopp.getPosition().y + (2 * goalkeeperopp.getRadius())) >= poleY2)
			goalkeeperopp_dir = 0;
		if (goalkeeperopp_dir == 1)
			goalkeeperopp.move(0.f, 3.f);
		if (goalkeeperopp_dir == 0)
			goalkeeperopp.move(0.f, -3.f);
		static int goalkeeperplay_dir = 2;
		if (goalkeeperplay.getPosition().y <= poleY1)
			goalkeeperplay_dir = 1;
		if ((goalkeeperplay.getPosition().y + (2 * goalkeeperplay.getRadius())) >= poleY2)
			goalkeeperplay_dir = 0;
		if (goalkeeperplay_dir == 1)
			goalkeeperplay.move(0.f, 3.f);
		if (goalkeeperplay_dir == 0)
			goalkeeperplay.move(0.f, -3.f);




		int  ina_index = 0;
		bool check_for_ina = false;
		for (int i = 0; i < 10; i++)
		{
			if (inaplayer_active[i] == "Blue")
			{
				ina_index = i;
				check_for_ina = true;
			}
			if (check_for_ina)
				break;
		}
		if (inaplayer_active[ina_index] == "Blue" && game_start)
		{
			if (Keyboard::isKeyPressed(Keyboard::Right) && inaplayer[ina_index].getPosition().x + (2 * (inaplayer[ina_index].getRadius())) < window.getSize().x)
				inaplayer[ina_index].move(3, 0);
			if (Keyboard::isKeyPressed(Keyboard::Left) && inaplayer[ina_index].getPosition().x > 0)
				inaplayer[ina_index].move(-3, 0);
			if (Keyboard::isKeyPressed(Keyboard::Up) && inaplayer[ina_index].getPosition().y > boundupY)
				inaplayer[ina_index].move(0, -3);
			if (Keyboard::isKeyPressed(Keyboard::Down) && inaplayer[ina_index].getPosition().y + (2 * (inaplayer[ina_index].getRadius())) < bounddownY)
				inaplayer[ina_index].move(0, 3);
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				inaplayer[ina_index].setFillColor(Color::Green);
				inaplayer_active[ina_index] = "Green";
				for (int a = 0; a < 10; a++)
				{
					if (a != ina_index)
					{
						inaplayer_D1 = pow((inaplayer[ina_index].getPosition().x - inaplayer[a].getPosition().x), 2.0);
						inaplayer_D2 = pow((inaplayer[ina_index].getPosition().y - inaplayer[a].getPosition().y), 2.0);
						inaplayer_D[a] = sqrt(inaplayer_D1 + inaplayer_D2);
					}
				}
				for (int a = 0; a < 10; a++)
				{
					if (a != ina_index)
					{
						static double small = inaplayer_D[a];
						if (inaplayer_D[a] < small)
						{
							small = inaplayer_D[a];
							make_ina_active = a;
						}
					}
					if (a == 9)
					{
						inaplayer[make_ina_active].setFillColor(Color::Blue);
						inaplayer_active[make_ina_active] = "Blue";
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				inaplayer[ina_index].setFillColor(Color::Green);
				inaplayer_active[ina_index] = "Green";
				football.setPosition(Vector2f(inaplayer[ina_index].getPosition().x, inaplayer[ina_index].getPosition().y));
				football_check = true;
				football_check_goal = true;
			}
			for (int i = 0; i < 3; i++)
			{
				if (inaplayer[ina_index].getPosition().x > oppplayer[i].getPosition().x)
				{
					oppplayer_tray2 = false;
					oppplayer_tray3 = false;
					oppplayer_tray4 = false;
					float angle = atan2(oppplayer[i].getPosition().y - inaplayer[ina_index].getPosition().y, oppplayer[i].getPosition().x - inaplayer[ina_index].getPosition().x);
					angle = angle * 180 / (atan(1) * 4);
					Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
					oppplayer[i].move(newpos.x, newpos.y);
				}
				if (inaplayer[ina_index].getPosition().x < oppplayer[i].getPosition().x)
					oppplayer_tray2 = true;
				if (oppplayer[i].getGlobalBounds().intersects(inaplayer[ina_index].getGlobalBounds()))
				{
					oppplayer[i].setFillColor(Color::Yellow);
					inaplayer[ina_index].setFillColor(Color::Green);
					inaplayer_active[ina_index] = "Green";
					goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
					goto restart;
				}
			}
			if (oppplayer_tray2)
			{
				for (int i = 3; i < 5; i++)
				{
					if (inaplayer[ina_index].getPosition().x > oppplayer[i].getPosition().x)
					{
						oppplayer_tray3 = false;
						oppplayer_tray4 = false;
						float angle = atan2(oppplayer[i].getPosition().y - inaplayer[ina_index].getPosition().y, oppplayer[i].getPosition().x - inaplayer[ina_index].getPosition().x);
						angle = angle * 180 / (atan(1) * 4);
						Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
						oppplayer[i].move(newpos.x, newpos.y);
					}
					if (inaplayer[ina_index].getPosition().x < oppplayer[i].getPosition().x)
						oppplayer_tray3 = true;
					if (oppplayer[i].getGlobalBounds().intersects(inaplayer[ina_index].getGlobalBounds()))
					{
						oppplayer[i].setFillColor(Color::Yellow);
						inaplayer[ina_index].setFillColor(Color::Green);
						inaplayer_active[ina_index] = "Green";
						goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
						goto restart;
					}
				}
			}
			if (oppplayer_tray3)
			{
				for (int i = 5; i == 5; i++)
				{
					if (inaplayer[ina_index].getPosition().x > oppplayer[i].getPosition().x)
					{
						oppplayer_tray2 = false;
						oppplayer_tray4 = false;
						float angle = atan2(oppplayer[i].getPosition().y - inaplayer[ina_index].getPosition().y, oppplayer[i].getPosition().x - inaplayer[ina_index].getPosition().x);
						angle = angle * 180 / (atan(1) * 4);
						Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
						oppplayer[i].move(newpos.x, newpos.y);
					}
					if (inaplayer[ina_index].getPosition().x < oppplayer[i].getPosition().x)
						oppplayer_tray4 = true;
					if (oppplayer[i].getGlobalBounds().intersects(inaplayer[ina_index].getGlobalBounds()))
					{
						oppplayer[i].setFillColor(Color::Yellow);
						inaplayer[ina_index].setFillColor(Color::Green);
						inaplayer_active[ina_index] = "Green";
						goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
						goto restart;
					}
				}
			}
			if (oppplayer_tray4)
			{
				for (int i = 6; i < 10; i++)
				{
					if (inaplayer[ina_index].getPosition().x > oppplayer[i].getPosition().x)
					{
						oppplayer_tray2 = false;
						oppplayer_tray3 = false;
						float angle = atan2(oppplayer[i].getPosition().y - inaplayer[ina_index].getPosition().y, oppplayer[i].getPosition().x - inaplayer[ina_index].getPosition().x);
						angle = angle * 180 / (atan(1) * 4);
						Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
						oppplayer[i].move(newpos.x, newpos.y);
					}
					if (oppplayer[i].getGlobalBounds().intersects(inaplayer[ina_index].getGlobalBounds()))
					{
						oppplayer[i].setFillColor(Color::Yellow);
						inaplayer[ina_index].setFillColor(Color::Green);
						inaplayer_active[ina_index] = "Green";
						goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
						goto restart;
					}
				}
			}
			if (inaplayer[ina_index].getGlobalBounds().intersects(goalkeeperopp.getGlobalBounds()))
			{
				inaplayer[ina_index].setFillColor(Color::Green);
				inaplayer_active[ina_index] = "Green";
				goalkeeperopp.setFillColor(Color::Yellow);
				goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
				goto restart;
			}
		}
		int ina_players_rand = rand() % 10;
		if (ina_players_rand != ina_index)
		{
			float angle = atan2(inaplayer[ina_players_rand].getPosition().y - goalkeeperplay.getPosition().y, inaplayer[ina_players_rand].getPosition().x - goalkeeperplay.getPosition().x);
			angle = angle * 180 / (atan(1) * 4);
			Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
			inaplayer[ina_players_rand].move(newpos.x, newpos.y);
		}



		int opp_players_rand = rand() % 10;
		float angle = atan2(oppplayer[opp_players_rand].getPosition().y - goalkeeperopp.getPosition().y, oppplayer[opp_players_rand].getPosition().x - goalkeeperopp.getPosition().x);
		angle = angle * 180 / (atan(1) * 4);
		Vector2f newpos((cos(angle)) * 2, (sin(angle)) * 2);
		oppplayer[opp_players_rand].move(newpos.x, newpos.y);


		window.clear();
		window.draw(middleline, 2, Lines);
		window.draw(boundup, 2, Lines);
		window.draw(bounddown, 2, Lines);
		window.draw(poleopp, 2, Lines);
		window.draw(poleplay, 2, Lines);
		window.draw(goalkeeperopp);
		window.draw(goalkeeperplay);
		for (int i = 0; i < 10; i++)
			window.draw(oppplayer[i]);
		for (int i = 0; i < 10; i++)
			window.draw(inaplayer[i]);
		if (football_check)
		{
			window.draw(football);
			if (football_check_goal)
			{
				football.move(-3, 0);
				if (football.getGlobalBounds().intersects(goalkeeperopp.getGlobalBounds()))
				{
					goalkeeperopp.setFillColor(Color::Yellow);
					football_check = false;
					football_check_goal = false;
					goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
					goto restart;
				}
				if (football.getPosition().x < 10 && football.getPosition().y > poleY1&& football.getPosition().y < poleY2)
				{
					goal_by_ina_int++;
					goal_by_ina.setString(to_string(goal_by_ina_int));
					goto restart;
				}
				if (football.getPosition().x < 0 && (football.getPosition().y < poleY1 || football.getPosition().y > poleY2))
				{
					goto restart;
				}
				for (int i = 0; i < 10; i++)
				{
					if (football.getGlobalBounds().intersects(oppplayer[i].getGlobalBounds()))
					{
						oppplayer[i].setFillColor(Color::Yellow);
						football_check = false;
						football_check_goal = false;
						goal_points_system(points_by_opp_int, points_by_opp, goal_by_opp_int, goal_by_opp);
						goto restart;
					}
				}
			}
		}
		window.draw(goal_by_opp);
		window.draw(goal_by_ina);
		window.draw(points_by_opp);
		window.draw(timer_text);
		window.draw(winner_text);
		window.display();
	}
	return 0;
};