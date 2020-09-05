//
//  main.cpp
//  Find the City With the Smallest Number of Neighbors at a Threshold Distance
//
//  Created by Chuong Lê on 9/5/20.
//  Copyright © 2020 Chuong Lê. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> Dis;
        for (int i = 0; i < n; i++) {
            vector<int> d(n,INT_MAX);
            Dis.push_back(d);
            Dis[i][i] = 0;
        }
        
        for (int i = 0 ; i < edges.size(); i++) {
            int a,b,c;
            a = edges[i][0];
            b = edges[i][1];
            c = edges[i][2];
            Dis[a][b] = c;
            Dis[b][a] = c;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (Dis[i][k] != INT_MAX && Dis[k][j] != INT_MAX && Dis[i][k] + Dis[k][j] < Dis[i][j] )
                        Dis[i][j] = Dis[i][k] + Dis[k][j];
                }
            }
        }
        vector<int> E(n,0);
        int m = INT_MAX;
        for (int i = 0 ; i < n; i++) {
            for (int j = 0; j < n ; j++) {
                if(Dis[i][j] <= distanceThreshold && i != j)
                {
                    E[i] += 1;
                }
            }
            if(E[i] < m)
                m = E[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if(E[i] == m)
                return i;
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> Edges ;
    int n,m,distanceThreshold;
    freopen("sample_input.txt", "r", stdin);
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        vector<int> e(3,0);
        Edges.push_back(e);
    }
    for (int i = 0; i < m; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        Edges[i][0] = a;
        Edges[i][1] = b;
        Edges[i][2] = c;
    }
    cin>>distanceThreshold;
    Solution s;
    cout<<s.findTheCity(n , Edges, distanceThreshold)<<endl;
    return 0;
}
