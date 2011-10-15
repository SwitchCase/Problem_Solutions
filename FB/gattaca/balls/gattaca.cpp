#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
struct gene{
	int start;
	int stop;
	int weight;
};
bool cmp(gene a,gene b){

return a.stop < b.stop;
		
}
int main(int argc,char *argv[]){
	ifstream fin(argv[1]);
	int datalen;
	fin>>datalen;
	
	int numlines=datalen/80;
	if(datalen%80!=0)
		numlines+=1;
	for(int i=0;i<numlines;i++){
		string s;
		fin>>s;
	}
	int numgenes;
	fin>>numgenes;
	
	vector<gene> arr;
	for(int i=0;i<numgenes;i++){
		gene temp;
		fin>>temp.start>>temp.stop>>temp.weight;
		arr.push_back(temp);
	}
	
	stable_sort(arr.begin(),arr.end(),cmp);
	
	int maximum=0;
	int cost[datalen+1];
	//vector<int> cost;
	//cost.resize(datalen+1);
	for(int i=0;i<arr[0].stop-1;i++)
		cost[i]=0;
	cost[arr[0].stop]=arr[0].weight;
	
	for(int i=1;i<numgenes;i++){
		
			for (int j = arr[i-1].stop+1; j < arr[i].stop; j++) {
					cost[j] = cost[arr[i-1].stop];
			}
			
			int tempcost = cost[arr[i].stop-1];
			if (arr[i-1].stop == arr[i].stop && cost[arr[i].stop]>cost[arr[i].stop-1])
				{
					tempcost = cost[arr[i].stop];
				}
						
			
			int newcost=arr[i].weight;
			if(arr[i].start-1 >=0)
				newcost+=cost[arr[i].start-1];
			if(tempcost > newcost)
				cost[arr[i].stop] = tempcost;
			else
				cost[arr[i].stop] = newcost;	
			
			if (maximum < cost[arr[i].stop]) {
				maximum = cost[arr[i].stop];				
			}
	}
	cout<<maximum<<"\n";	

}
