class Twitter {
    class tweet {
        public:
        int id;
        int time;
        tweet(int id, int time) {
            this->id = id;
            this->time = time;
        }
    };
    class user {
        public:
        vector<tweet*>tweetid;
        set<int> followid;
        user(int t, int f, int time) {
        if (t > 0)
            this->tweetid.push_back(new tweet(t, time));
        if (f > 0)
            this->followid.insert(f);
        }
    };
    
    class cmp {
        public:
        bool operator()(tweet *a, tweet *b) {
            return a->time < b->time;
        }
    };

public:
    unordered_map<int, user*> map;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time ++;
        if (map.find(userId) != map.end()) {
            map[userId]->tweetid.push_back(new tweet(tweetId, time));
        } else {
            map[userId] = new user(tweetId, -1, time);
        }
    }

    void add_news(priority_queue<tweet*, vector<tweet*>, cmp> &pq, user *u) {
        for (auto it = u->tweetid.begin(); it != u->tweetid.end(); it++) {
            pq.push(*it);
        }
    } 
    vector<int> getNewsFeed(int userId) {
        vector<int>ret;

        priority_queue <tweet*, vector<tweet*>, cmp> pq;
    
        if (map.find(userId) == map.end())
            return ret; 

        add_news(pq, map[userId]);
        for (auto it = map[userId]->followid.begin(); it != map[userId]->followid.end(); it++) {
            if (map.find(*it) == map.end())
                continue;
            add_news(pq, map[*it]);
        }
            
        
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            ret.push_back(pq.top()->id);
            pq.pop();
        }
        
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if (map.find(followerId) != map.end()) {
            map[followerId]->followid.insert(followeeId);
        } else {
            map[followerId] = new user(-1, followeeId, 0);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        map[followerId]->followid.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */