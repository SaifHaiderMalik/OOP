#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class xyz{
    string name;
    int number;
    double floatNum;
}

class Record{
    char code[20], name[50], gender[7], temp[20], rec;
    char *file;
    int age;
    vector<xyz> xyzVec;
    vector<string> strVec;
    vector<int> intVec;
    vector<double> dblVec;
    public:
        Record(){file="File.BIN";}

        void saveRecords(){
            fstream Write(file,ios::out | ios::app | ios::binary);
            if(!Write)
                exit(1);
            Record obj;

            while(true){
                cout<<"Enter Code of Restaurant: ";cin.ignore();cin.getline(code,20);cout<<endl;
				obj.setCode(code);
                cout<<"Enter Name :";cin.getline(name,50);cout<<endl;
				obj.setName(name);
                obj.setGender();
                obj.setAge();
                Write.write(reinterpret_cast<char*> (&obj),sizeof(obj));
                askAnother:
				cout<<"Do you want to enter another record: (Y/N)"<<endl;
                cin>>rec;
                if(rec=='Y'||rec=='y'){
                	system("cls");
                	continue;
				} else if (rec=='N'||rec=='n'){
					system("cls");
					break;
				} else {
					cout<<"Invalid Input: options are (Y/N)"<<endl;
					goto askAnother;
				}
            }

            Write.close();
        }

        void deleteRecords(){
            bool flag=false;
            fstream Delete(file,ios::in | ios::binary);
            Record obj;

            if(!Delete){
                cout<<"No Records found or Error in opening file!"<<endl;
                system("pause");
                system("cls");
        	}
            fstream Copy("Temp.BIN",ios::out | ios::binary);
            if(!Copy){
            	cout<<"Error in opening file"<<endl;
            	exit(1);
            }
            
            cout<<"Enter Code of Restaurant Code: ";cin.ignore();cin.getline(code, 20);
            Delete.seekg(0, ios::beg);

            while(Delete.read(reinterpret_cast<char*> (&obj), sizeof(obj))){
                
                if(strcmp(code,obj.getCode())!=0){
                    Copy.write(reinterpret_cast<char*> (&obj), sizeof(obj));
                } else if(strcmp(code,obj.getCode())==0){
                    flag=true;
                }
            }

            Copy.close();
            Delete.close();
            if(flag!=true){
                remove("Temp.BIN");
                cout<<endl<<"No records matched your restaurant"<<endl<<endl;
                system("pause");
                system("cls");
            } else{
                remove(file);
                rename("Temp.BIN",file);
                cout<<endl<<"Restaurant: "<<code<<" has been successfully removed"<<endl<<endl;
                system("pause");
                system("cls");
            }
        }

        void displayRecords(){
            fstream Read(file, ios::in | ios::binary);
            Record obj;
            if(!Read)
                exit(1);

            cout<<"Records: "<<endl;
            while(Read.read(reinterpret_cast<char*> (&obj), sizeof(obj))){
                cout << "Code: " << obj.getCode() << endl <<"Name: " << obj.getName() << endl << "Age: " << obj.getAge() << endl << "Gender: " << obj.getGender() << endl << endl;
            }
            system("pause");
            system("cls");
        }

        void setCode(char code[]){strcpy(this->code,code);}
        void setName(char name[]){strcpy(this->name,name);}
        void setGender(){
            askGen:
            cout<<"Enter Gender: ";cin.getline(temp,7);cout<<endl;
            if(strcmp(temp,"male")||strcmp(temp,"Male")||strcmp(temp,"m")||strcmp(temp,"M")){
                strcpy(gender,temp);
            } else if(strcmp(temp,"female")||strcmp(temp,"Female")||strcmp(temp,"f")||strcmp(temp,"F")){
                strcpy(gender,temp);
            } else if(strcmp(temp,"Other")||strcmp(temp,"other")){
                strcpy(gender,temp);
            } else{
                cout<<"Invalid Input: Options (Male, Female, Other)"<<endl;
                system("pause");
                system("cls");
                goto askGen;
            }
        }
        void setAge(){
        	int tempi;
            askAge:
            cout<<"Enter Age: ";cin>>tempi;cout<<endl;
            if(tempi>0){
                age=tempi;
            } else{
                cout<<"Invalid"<<endl<<endl;
                goto askAge;
            }
        }

        char* getCode(){return code;}
        char* getName(){return name;}
        char* getGender(){return gender;}
        int getAge(){return age;}
        
        void input(){
        	int choice;
    		cout<<"1- Save Record/s"<<endl<<"2- Display Records"<<endl<<"3- Delete Records"<<endl<<"0- Quit"<<endl<<"Enter Selection: ";cin>>choice;system("cls");
    		Record input;
    		while (choice!=0)
    		{
        		switch (choice)
        		{
            		case 1:
                		input.saveRecords();
                		break;
            		case 2:
                		input.displayRecords();
                		break;
            		case 3:
                		input.deleteRecords();
						break;
            		case 0:
            			break;
            			break;
            		default:
                		cout<<"Invalid Input"<<endl;
                		system("pause");
                		system("cls");
                		break;
        		}
        		cout<<"1- Save Record/s"<<endl<<"2- Display Records"<<endl<<"3- Delete Records"<<endl<<"0- Quit"<<endl<<"Enter Selection: ";cin>>choice;
        		system("cls");
    		}
		}
};

int main(){
    Record create;
    create.input();
}
