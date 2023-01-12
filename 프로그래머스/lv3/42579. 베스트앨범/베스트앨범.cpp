#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct genr{
    string gen;
    int cnt;
    int genre_int;
};

struct song{
    int idx;
    string gen;
    int cnt;
    int genre_int;
};

int compare(genr left, genr right){
    if(left.cnt > right.cnt) return 1;
    else return 0;
}

int song_compare(song left, song right){
    if(left.genre_int < right.genre_int) return 1;
    else if(left.genre_int > right.genre_int) return 0;
    else{
        if(left.cnt > right.cnt) return 1;
        else if (left.cnt < right.cnt) return 0;
        else{
            if(left.idx < right.idx) return 1;
            else return 0;
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<genr> set_genres;   
    vector<song> songs;
    
    for(int i=0;i<genres.size();i++){
        
        int flag = 0;
        for(int g=0;g<set_genres.size();g++){
            if(genres[i] == set_genres[g].gen){
                flag = 1;
                break;
            }
        }
        
        if(flag==0) set_genres.push_back({genres[i],0,-1});
    }
    
    for(int i=0;i<genres.size();i++){
        
        songs.push_back({i,genres[i],plays[i],-1});
        
        for(int g=0;g<set_genres.size();g++){
            if(genres[i] == set_genres[g].gen){
                set_genres[g].cnt += plays[i];
                break;
            }
        }
    }
    
    sort(set_genres.begin(),set_genres.end(),compare);
    
    for(int g=0;g<set_genres.size();g++){
        set_genres[g].genre_int = g;
        for(int i=0;i<genres.size();i++){
            if(songs[i].gen == set_genres[g].gen){
                songs[i].genre_int = g;
            }
        }
    }
    
    sort(songs.begin(),songs.end(), song_compare);
    
    int bef = -1;
    int banbok = 0;
    for(int i=0;i<genres.size();i++){
        if(bef == songs[i].genre_int){
            banbok++;
        }else{
            bef = songs[i].genre_int;
            banbok = 1;
        }
        if(banbok >= 3) continue;
        answer.push_back(songs[i].idx);
    }
    
    return answer;
}