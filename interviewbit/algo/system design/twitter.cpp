#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL
#define vi vector<int>
#define vl vector<ll>
#define moi map<int, int>
#define umoi unordered_map<int, int>
#define mol map<ll, ll>
#define umol unordered_map<ll, ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define psi pair<string, int>
#define pis pair<int, string>
#define vp vector<pair<int, int>>

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

//  Definition of Tweet:
class Tweet
{
public:
    static int count;
    int user_id;
    int like_count;
    // user id
    vector<int>liked_By;
    string text;
    int id;
    Tweet(int userId, string tweet_text)
    {
        id = count;
        like_count =0;
        user_id = userId;
        text = tweet_text;
        count++;
    }
};
int Tweet::count = 1;


#include <list>

class MiniTwitter
{
    map<int, unordered_set<int>> following;
    list<pair<int, Tweet>> tweets;
    map<int, vector<int>>likedTweets;
    map<int, Tweet>allTweets;
    map<int, vector<Tweet>>Retweet;
public:
    MiniTwitter()
    {
    }
    Tweet postTweet(int user_id, string &tweet_text)
    {
        Tweet t = Tweet(user_id, tweet_text);
        allTweets[t.id] = t;
        tweets.push_front({user_id, t});
        return t;
    }
    Tweet reTweet(int id, int user_id, string tweet_text){
        Retweet[id].push_back(Tweet(user_id, tweet_text));
    }

    vector<Tweet>getRetweets(int id){
        return Retweet[id];
    }

    vector<Tweet> getNewsFeed(int userId)
    {
        int count = 10;
        vector<Tweet> feed;
        for (auto x : tweets)
        {
            if (((x.first == userId) || (following[userId].find(x.first) != following[userId].end())) && count > 0)
            {
                feed.push_back(x.second);
                count -= 1;
            }
        }
        return feed;
    }

    vector<Tweet> getTimeline(int userId)
    {
        int count = 10;
        vector<Tweet> feed;
        for (auto x : tweets)
        {
            if ((x.first == userId) && count > 0)
            {
                feed.push_back(x.second);
                count -= 1;
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        if (following[followerId].find(followeeId) == following[followerId].end())
        {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        if (following[followerId].find(followeeId) != following[followerId].end())
        {
            following[followerId].erase(followeeId);
        }
    }

    void like(int userId, int tweetId){
        for(auto x: tweets){
            if(x.second.id == tweetId){
                x.second.liked_By.push_back(userId);
                likedTweets[userId].push_back(tweetId);
            }
        }
        cout<<"invalid tweet id"<<endl;
    }

    vector<Tweet> likedTweets(int userId){
        vector<Tweet>ans;
        for(auto x: likedTweets[userId]){
            ans.push_back(allTweets[x]);
        } 
        return ans;  
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ReadCP();
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}