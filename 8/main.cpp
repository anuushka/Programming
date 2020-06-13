#include "cube.h"
#include<iostream>
using namespace std;

int main()
{
  Cube cubik;
  cout<<"________________________| RUBIK'S CUBE SOLVER |________________________"<<endl<<endl;
  cout<<"Input :"<<endl<<endl;
  cout<<"White Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.white[i];}
  cout<<"Red Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.red[i];}
  cout<<"Orange Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.orange[i];}
  cout<<"Blue Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.blue[i];}
  cout<<"Green Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.green[i];}
  cout<<"Yellow Side : ";
  for(int i=0;i<9;++i)
  {cin>>cubik.yellow[i];}
  //-----------------------------------
  cout<<"\n-------------------------------------------------\n"<<endl;
  cout<<"Turn these sides of the Cube in Clockwise Direction by 90 degrees in this exact order..."<<endl<<endl;
  cubik.solve_white_cross();
  cubik.solve_white_corners();
  cubik.solve_middle_layer();
  cubik.solve_yellow_cross();
  cubik.solve_yellow_corners();
  cubik.yellow_corner_orientation();
  cubik.yellow_edges_colour_arrangement();
  //------------------------------------
  cout<<"\n\n-------------------------------------------------"<<endl<<endl;
  cout<<"Your Rubik's Cube is now SOLVED!\n\nOutput : "<<endl<<endl;
  cout<<"White Side : ";
  cubik.display(cubik.white);
  cout<<"Red Side : ";
  cubik.display(cubik.red);
  cout<<"Orange Side : ";
  cubik.display(cubik.orange);
  cout<<"Blue Side : ";
  cubik.display(cubik.blue);
  cout<<"Green Side : ";
  cubik.display(cubik.green);
  cout<<"Yellow Side : ";
  cubik.display(cubik.yellow);
  return 0;
}
