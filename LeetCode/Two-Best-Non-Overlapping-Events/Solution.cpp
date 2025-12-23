set<int> S;
for(auto event : events){
    S.insert(event[0]);
    S.insert(event[1]);
}
unordered_map<int, int> new_val;
int M = 1;
for(auto x : S){
    new_val[x] = M;
    M += 1;
}
for(auto &event : events){
    event[0] = new_val[event[0]];
    event[1] = new_val[event[1]];
}