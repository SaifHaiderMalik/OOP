#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Participant{

    string name;
    string id;
    int score;

    public:

    void Input(string _name,string _id,int _score){

        name = _name;
        id = _id;
        score = _score;
        ofstream os("Participant.dat", ios::app);
        os << name <<endl;
        os << id <<endl;
        os << score << endl;
        os.close();
    }

    void Output(string _id){

        char ch;
        string _score;
        
        ifstream is("Participant.dat");

        while(true){

            if(is.eof()){

                break;
            }
            getline(is, name);
            getline(is, id);
            getline(is, _score);
            //is >> id >> score;
            cout << name << id << _score << endl;
            //is >> name >> id >> score;

            if(id == _id){
                cout << "Name: " << name <<endl;
                cout << "ID: " << id <<endl;
                cout << "Score: " << _score <<endl;
                break;
            }

        }
        is.close();
    }


    void Max(){

        ifstream is("Participant.dat");
		string name, _name, _score;
        string id, _id;
		//int score;
		int max = 0;

		while(true) {

            if(is.eof()){

                break;
            }

            getline(is, _name);
            getline(is, _id);
            getline(is, _score);
            //is >> name >> id >> score;

			if (stoi(_score) > max) {
                name = _name;
                id = _id;
				max = stoi(_score);
			}
		}

		cout << "Participant with highest score: " <<endl;
		cout << "Name: " << name <<endl;
		cout << "ID: " << id <<endl;
		cout << "Score: " << max <<endl;
		is.close();
	}
    
};


int main(void){

    string name;
    string id;
    int score;
    int count; 
    
    ofstream os("Participant.dat");
    os.close();

    Participant p[3];

    for(int i = 0; i < 3;i++){

        cout << "Enter Name: " <<endl;
        getline(cin,name);
        
        cout << "Enter Id: " <<endl;
        getline(cin, id);

        cout << "Enter Score: " <<endl;
        cin >> score;

        p[i].Input(name,id,score);

        cin.ignore();
    }

    cout << "Enter ID to Find: " <<endl;
    getline(cin, id);

    Participant ob;
    ob.Output(id);

    ob.Max();
}