#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int G, P, S, K, pilot;
    cin >> G >> P;
    while (G != 0 && P != 0) 
    {
        vector<vector<int>> results(G, vector<int>(P));
        for (int i = 0; i < G; i++) 
        {
            for (int j = 0; j < P; j++) 
            {
                cin >> results[i][j];
            }
        }
        cin >> S;
        while (S!=0) 
        {
            cin >> K;
            vector<int> points(P,0);
            
            for (int i = 0; i < K; i++) 
            {
                cin >> points[i];
            }
            vector<int> totalPoints(P);
            for (int i = 0; i < G; i++) 
            {
                for (int j = 0; j < P; j++) 
                {
                    pilot = results[i][j] - 1;
                    totalPoints[j] += points[pilot];
                }
            }
            
            int maxPoints = *max_element(totalPoints.begin(), totalPoints.end());
            vector<int> champions;
            for (int i = 0; i < P; i++) 
            {
                if (totalPoints[i] == maxPoints) 
                {
                    champions.push_back(i + 1);
                }
            }

            for (int i = 0; i < champions.size(); i++) 
            {
                cout << champions[i];
                if (i < champions.size() - 1) 
                {
                    cout << " ";
                }
            }
            cout << endl;
            S=S-1;
        }
        cin >> G >> P;
    }
    return 0;
}







