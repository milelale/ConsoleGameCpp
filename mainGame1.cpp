#include <iostream>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
bool gameOver = false;
int money = 100, response, numOfProducers = 0, numOfTurns = -3;;
vector<int> locationOfObjects; 
class object{
	public:
		int health;
		bool alive;
		int locationx;
		int locationy;
		int price;
		int type;
};
object producer{
	producer.price = 100,
	producer.health = 1,
	producer.alive = true,
 	producer.type = 7439
};
object shooter{
	shooter.price = 200,
	shooter.health = 1,
	shooter.alive = true,
	shooter.alive = 9097
};
object wall{
	wall.price = 150,
	wall.health = 5,
	wall.alive = true,
	wall.type = 4546
};
object enemy1{
	enemy1.health = 4,
	enemy1.alive = true,
	enemy1.type = 2384,
	enemy1.locationy = 10
};
object enemy2{
	enemy2.health = 6,
	enemy2.alive = true,
	enemy2.type = 6412,
	enemy2.locationy = 10
};
void battleField(){
	cout << money << "$" << endl;
	for(int i = 1;i <= 6;i++){
			for(int j = 1;j <= 11;j++){
				
					if(i == 1){
						cout << j - 1 << " ";
					}
					else if(j == 1){
						cout << i - 1 << " ";
					}
					else{
						cout << "# ";
					}	
					
						for(int l = 0;l < locationOfObjects.size();l+=4){
							if(locationOfObjects[l+1] + 1 == i && locationOfObjects[l+2] + 1 == j){
								cout << "\b\b";
								
								if(locationOfObjects[l] == producer.type){
									if(locationOfObjects[l+3] > 0){
										cout << "P ";
									}
									else{
										cout << "# ";
									}
								}
								else if(locationOfObjects[l] == shooter.type){
									if(locationOfObjects[l+3] > 0){
										cout << "S ";
									}
									else{
										cout << "# ";
									}
								}
								else if(locationOfObjects[l] == wall.type){
									if(locationOfObjects[l+3] > 0){
										cout << "W ";
									}
									else{
										cout << "# ";
									}
								}
								else if(locationOfObjects[l] == enemy1.type){
									if(locationOfObjects[l+3] > 0){
										cout << "E1 ";
									}
									else{
										cout << "# ";	
									}
									
									for(int k = 0;k < locationOfObjects.size();k+=4){
										if(locationOfObjects[k] == producer.type && locationOfObjects[l+1] == locationOfObjects[k+1] && locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+2]++;
											}
											if(locationOfObjects[l+3] > 0){
												locationOfObjects[k+3]--;
											}	
										}
										if(locationOfObjects[k] == shooter.type && locationOfObjects[l+1] == locationOfObjects[k+1]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+3]--;
											}	
											if(locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
												if(locationOfObjects[k+3] > 0){
													locationOfObjects[l+2]++;
												}
												if(locationOfObjects[l+3] > 0){
													locationOfObjects[k+3]--;
												}	
											}
										}
										if(locationOfObjects[k] == wall.type && locationOfObjects[l+1] == locationOfObjects[k+1] && locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+2]++;
											}
											if(locationOfObjects[l+3] > 0){
												locationOfObjects[k+3]--;
											}	
										}
									}
									
									locationOfObjects[l+2]--;
									if(locationOfObjects[l+2] == 0 && locationOfObjects[l+3] > 0){
										gameOver = true;
									}
								}
								
								else if(locationOfObjects[l] == enemy2.type){
									if(locationOfObjects[l+3] > 0){
										cout << "E1 ";
									}
									else{
										cout << "# ";	
									}
									
									for(int k = 0;k < locationOfObjects.size();k+=4){
										if(locationOfObjects[k] == producer.type && locationOfObjects[l+1] == locationOfObjects[k+1] && locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+2]++;
											}
											if(locationOfObjects[l+3] > 0){
												locationOfObjects[k+3]--;
											}	
										}
										if(locationOfObjects[k] == shooter.type && locationOfObjects[l+1] == locationOfObjects[k+1]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+3]--;
											}	
											if(locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
												if(locationOfObjects[k+3] > 0){
													locationOfObjects[l+2]++;
												}
												if(locationOfObjects[l+3] > 0){
													locationOfObjects[k+3]--;
												}	
											}
										}
										if(locationOfObjects[k] == wall.type && locationOfObjects[l+1] == locationOfObjects[k+1] && locationOfObjects[l+2] - 1 == locationOfObjects[k+2]){
											if(locationOfObjects[k+3] > 0){
												locationOfObjects[l+2]++;
											}
											if(locationOfObjects[l+3] > 0){
												locationOfObjects[k+3]--;
											}	
										}
									}
									
									locationOfObjects[l+2]--;
									if(locationOfObjects[l+2] == 0 && locationOfObjects[l+3] > 0){
										gameOver = true;
									}
								}
							}
						}
			}
		cout << endl << endl;
	}	
}
void responseTurn(){
	
	cout << endl << "What do you want to place this turn?" << endl << "1.Type anything to skip the turn" << endl << "2.Type 2 for a producer - 100$" << endl << "3.Type 3 for a shooter 200$" << endl << "4.Type 4 for a wall - 150$" << endl;
	cin >> response;
	
	switch(response){
		case 2:
		if(producer.price > money){
			cout << "Unabale to buy. Not enough money";
			Sleep(1500);
			cout << endl;
		}
		else{
			money = money - producer.price;
			numOfProducers++;
			cout << "where do you want to place your producer?" << endl;
			cin >> producer.locationx >> producer.locationy;
			locationOfObjects.push_back(producer.type);
			locationOfObjects.push_back(producer.locationx);
			locationOfObjects.push_back(producer.locationy);
			locationOfObjects.push_back(producer.health);
		}
		break;

		case 3:
		if(shooter.price > money){
			cout << "Unabale to buy. Not enough money";
			Sleep(1500);
			cout << endl;
		}
		else{
			money = money - shooter.price;
			cout << "where do you want to place your shooter?" << endl;
			cin >> shooter.locationx >> shooter.locationy;
			locationOfObjects.push_back(shooter.type);
			locationOfObjects.push_back(shooter.locationx);
			locationOfObjects.push_back(shooter.locationy);
			locationOfObjects.push_back(shooter.health);
		}
		break;

		case 4:
		if(wall.price > money){
			cout << "Unabale to buy. Not enough money";
			Sleep(1500);
			cout << endl;

		}
		else{
			money = money - wall.price;
			cout << "where do you want to place your wall?" << endl;
			cin >> wall.locationx >> wall.locationy;
			locationOfObjects.push_back(wall.type);
			locationOfObjects.push_back(wall.locationx);
			locationOfObjects.push_back(wall.locationy);
			locationOfObjects.push_back(wall.health);
		}
		break;
	}
}
void micelanious(){
	if(numOfTurns % 5 == 0){
		enemy1.locationx = rand() % 5 + 1;
		if(0){
			locationOfObjects.push_back(enemy2.type);
			locationOfObjects.push_back(enemy2.locationx);
			locationOfObjects.push_back(enemy2.locationy);
			locationOfObjects.push_back(enemy2.health);
		}
		else{
			locationOfObjects.push_back(enemy1.type);
			locationOfObjects.push_back(enemy1.locationx);
			locationOfObjects.push_back(enemy1.locationy);
			locationOfObjects.push_back(enemy1.health);
		}
	}
	numOfTurns++;
	money = money + (25 * (numOfProducers + 1));
	system("CLS");
	if(gameOver == true){
		cout << "You died";
		Sleep(3000);
	}
}
int main(){
	srand(time(0));
	system("CLS");
	while(gameOver != true){
		battleField();
		responseTurn();
		micelanious();
	}
	return 0;
}
