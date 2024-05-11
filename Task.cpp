#include "Task.h"
#include "List.h"

int main() {
	Point start(1, 2);
	Point end(5, 4);
	size_t time = 50;
	Walk walk(start, end, time);

	start._x = 1.2; start._y = 78;
	end._x = 25; end._y = 185.3;
	time = 16;
	double price = 0.8;
	Bus bus(start, end, time, price);

	start._x = 1; start._y = 7;                                                                                                                                                  
        end._x = 5; end._y = 183;      
        time = 40;                                                                                                                                                
        price = 0.8;
	Metro metro(start, end, time, price);

	start._x = 1; start._y = 47;
        end._x = 35; end._y = 143;
        time = 30;                             
        price = 0.95;                                                                                                                                                                    	Trolley trolly(start, end, time, price);

	start._x = 1; start._y = 7;                                                                                                                                                     
        end._x = 59; end._y = 7183;
        time = 12;                             
        price = 1.8;                                                                                                                                                                    
        Taxi taxi(start, end, time, price);
	
	start._x = 15; start._y = 7;                                                                                                                                                    
        end._x = 85; end._y = 1883;                                                                                                                                                       	time = 10;                             
        price = 9.8;                                                                                                                                                                    
	char* path = new char[17]{'h', 't', 't', 'p', ':', '/', '/', 'd', 'r', 'i', 'v', 'e', '.', 'c', 'o', 'm' };
	Car car(start, end, time, price, path);

	List seq(walk);
	seq.push_back(bus);
	//seq.pop_back();
	seq.push_back(metro);
	seq.push_back(trolly);
	seq.push_back(taxi);
	seq.push_back(car);
	std::cout << seq;
}







