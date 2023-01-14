class DSU {
public:
    vector<char>parent;
    DSU() {
        for(char ch='a';ch<='z';ch++) {
            parent.emplace_back(ch);
        }
    }
    
    char find(char ch) {
        if(ch==parent[ch-'a']) {
            return ch;
        }
        return parent[ch-'a']=find(parent[ch-'a']);
    }
    
    void Union(char p1,char p2) {
        if(p1<p2) {
            parent[p2-'a']=p1;
        }else {
            parent[p1-'a']=p2;
        }
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU * dsu=new DSU();
        //DSU dsu;
        int n=s1.size();
        for(int i=0;i<n;i++) {
            char p1=dsu->find(s1[i]);
            char p2=dsu->find(s2[i]);
            if(p1!=p2) dsu->Union(p1,p2);
        }
        for(int i=0;i<baseStr.size();i++) {
            baseStr[i]=dsu->find(baseStr[i]);
        }
        return baseStr;
    }
};