#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
struct point
{
    float x, y;
};
float distance(const point& a, const point &b)
{
    return (a.x + b.x)*(a.x + b.x) + (a.y + b.y)*(a.y + b.y);
}
bool loadData(char file[], point data[], int &n)
{
	ifstream fi(file);
	if (!fi.is_open())
	{
		cout << "Khong mo duoc file" << endl;
		return false;
	}
    fi >> n;
    for (int i = 0; i<n; i++)
    {
        fi >> data[i].x >> data[i].y;
    }
    // string line;
	// int pos;
    // getline(fi, line);
    // n = stoi(line);
	// for (int i = 0; i < n && !fi.eof(); i++)
	// {
	// 	getline(fi, line);
	// 	pos = line.find(" ");
	// 	data[i].x = stof(line.substr(0, pos));
	// 	line = line.substr(pos + 1);
	// 	data[i].y = stof(line);
	// }
	fi.close();
    return true;
}

int* sortbyDistanceFrom(point pointData[], const int &n, const point &origin)
{
    int *sortedIndex = new int [n];
    for(int i = 0; i < n;sortedIndex[i] = i++);
    float *distanceData = new float[n];
    for (int i = 0; i < n; i++)
    {
        distanceData[i] = distance(pointData[i], origin);
    }
    for (int i = 0, max; i < n-1; i++)
    {
        max = i;
        for( int j = i+1; j < n; j++)
        {
            if (distanceData[max] < distanceData[j])
            {
                max = j;
            }
        }
        swap(sortedIndex[i], sortedIndex[max]);
        swap(distanceData[i], distanceData[max]);
    }
    delete[] distanceData;
    return sortedIndex;
}
int main()
{
    point data[50];
    int n;
    if(!loadData("Diem.txt", data, n))
        return 1;
    point A = {0, 0};
    int * sortedIndex = sortbyDistanceFrom(data, n, A);
    for (int i = 0; i < 50; i ++)
    {
        cout << float(data[sortedIndex[i]].x) << " " << float(data[sortedIndex[i]].y) << endl;
    }
    return 0;
}