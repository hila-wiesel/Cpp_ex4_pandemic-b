#include "Board.hpp"
#include<fstream>
#include <string>
#include <exception>

using namespace pandemic;
using namespace std;

Board::Board() {
    // open the file:
    std::ifstream file{"cities_map.txt"};
    if(!file.is_open()){ 
        throw runtime_error("faild open the file!");
    }
    string city;
    string color;
    string all_ni;
    string ni;

    while(!file.eof()){
        file >> city >> color;
        //insert the color
        color_inCity.insert({str2city[city],color});
        //insert the connection
        std::set<City> conc;
        disease_inCity.insert({str2city[city],0});
        getline(file, all_ni);  //get all neighbors (after color)
        stringstream ss;
        ss <<all_ni;
        while(ss >> ni){
            neighbors_inCity[str2city[city]].insert(str2city[ni]);
        }
        conc.clear();
    }
}



int& Board::operator[](City city) {
    return disease_inCity[city];
}

bool Board::is_clean(){
   for(map<City, int>::iterator iter = disease_inCity.begin(); iter != disease_inCity.end(); ++iter) {
       if (iter->second != 0) {
           return false;
       }
   }
       return true;
}

void Board::remove_cures(){
    medicanes.clear();
}

void Board::remove_stations(){
    research_station.clear();
}


// setters:

void Board::build_station_in(City city) {  
    research_station.insert(city);
}

void Board::add_medicane(Color color){
    medicanes.insert(color);
}


// getter:

bool Board::is_connected(City city1, City city2){
    set<City> ni = neighbors_inCity.find(city1)->second;
    bool ans = ni.find(city2) != ni.end();
    return ans;

}

bool Board::have_research_station_in(City city){
   return research_station.find(city) !=research_station.end();
}

bool Board::have_medicane_color(Color color) {
    return medicanes.find(color) != medicanes.end();
}

Color Board::city_to_color(City city){
    string color = color_inCity.find(city) ->second;
    return str2Color.find(color) -> second;
}

bool Board::city_exist(City city){ 
    return color_inCity.find(city) != color_inCity.end();
}



ostream& pandemic::operator<<(ostream& os, Board &board) {    //need to add research stations and is found cure for the deseases
    cout<< "The intensity of the pandemic in every city"<<endl;
    for(map<City, int>::iterator iter = board.disease_inCity.begin(); iter != board.disease_inCity.end(); ++iter) {
      City city = iter->first;
      string str_city;
        for(map <std::string, City>::iterator iter_city = board.str2city.begin(); iter_city != board.str2city.end(); ++iter_city){
            if(iter_city->second == city){
                str_city = iter_city->first;
                break;
            }
        }
        cout<<"The City is: "<< str_city << " The Intense of The desease is: "<< iter->second <<endl;
    }
    //show medicanes that already discover
    cout<< "The cure that already discover"<<endl;
    for(set<Color>::iterator iter = board.medicanes.begin(); iter != board.medicanes.end(); ++iter) {
        Color color = *iter;
        string str_color;
        for(map <std::string, Color>::iterator iter_color = board.str2Color.begin(); iter_color != board.str2Color.end(); ++iter_color){
            if(iter_color ->second == color){
                str_color = iter_color -> first;
                break;
            }
        }
        cout<<"The Color is: "<< str_color <<endl;
    }
    //show all exist research station :
    cout<< "The research station that built"<<endl;
    for(set<City>::iterator iter = board.research_station.begin(); iter != board.research_station.end(); ++iter) {
        City place = *iter;
        string str_city;
        for(map<string, City>::iterator iter_city = board.str2city.begin(); iter_city != board.str2city.end(); ++iter_city){
            if(iter_city ->second == place){
                str_city = iter_city -> first;
                break;
            }
        }
        cout<<"The City is: "<< str_city <<endl;
    }

    return os;
}