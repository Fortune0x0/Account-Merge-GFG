#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<vector<string>> ans;
		int n = accounts.size();
		vector<bool> vis(n, false);

		set<set<string>> q;

		for (int row = 0; row < n; ++row) {
			if (!vis[row]) {
				set<string> list(accounts[row].begin(), accounts[row].end());
				q.insert(list);
				while (!q.empty()) {
					auto it = q.begin();
					set<string> s_list = *it;
					int list_size = s_list.size();
					q.erase(it);

					for (int i = 0; i < n; ++i) {
						if (row == i || vis[i]) continue;
						for (int j = 1; j < accounts[i].size(); ++j) {
							if (accounts[row][0] == accounts[i][0]) {
								auto a = s_list.find(accounts[i][j]);
								if (a != s_list.end()) {
									for (auto b : accounts[i]) s_list.insert(b);
									vis[i] = true;
								}
							}
						}
					}
					if (list_size != s_list.size()) q.insert(s_list);
					else {
						vector<string> vec(s_list.begin(), s_list.end());
						ans.push_back(vec);
						break;
					}

				}
			}
		}
		return ans;
	}
};


int main() {
	
	Solution solu;
	
	vector<vector<string>> vec = { {"David","David0@m.co","David1@m.co"}, {"David","David3@m.co","David4@m.co"}, {"David","David4@m.co","David5@m.co"}, {"David","David2@m.co","David3@m.co"}, {"David","David1@m.co","David2@m.co"} };
	vector<vector<string>> vec_2 = { {"mark", "mark1@google.in", "mark1@google.in", "mark0@google.in", "mark1@gmail.com", "mark8@gmail.com", "mark2@mail.com"},
{"john", "john5@mail.com", "john5gfg.org", "john2@google.in", "john7@gmail.com", "john1@gmail.com", "john2@mail.com"},
{"mark", "mark9gfg.org", "mark4@google.in", "mark9@gmail.com", "mark4@gmail.com", "mark5@mail.com"},
{"bob", "bob3@mail.com", "bob3@mail.com", "bob4gfg.org", "bob4gfg.org", "bob9gfg.org", "bob7@mail.com", "bob7@google.in"},
{"bob", "bob7@google.in", "bob3@gmail.com", "bob9@google.in", "bob2@google.in", "bob3@mail.com"},
{"mark", "mark4@google.in", "mark4gfg.org", "mark5@gmail.com", "mark7@mail.com", "mark3gfg.org", "mark4gfg.org"},
{"kevin", "kevin9@mail.com", "kevin0@google.in", "kevin6gfg.org", "kevin9@google.in", "kevin6gfg.org"},
{"john", "john8@mail.com"},
{"alice", "alice6gfg.org", "alice6@gmail.com", "alice3@google.in", "alice9@gmail.com", "alice5@google.in", "alice1@mail.com", "alice8@mail.com", "alice8@mail.com"},
{"kevin", "kevin6gfg.org", "kevin5@gmail.com", "kevin2@google.in", "kevin0@google.in", "kevin1@mail.com", "kevin0@gmail.com"},
{"bob", "bob2@google.in", "bob0@mail.com", "bob2@gmail.com", "bob2@mail.com", "bob9@gmail.com", "bob2@mail.com", "bob6@mail.com", "bob4@gmail.com"},
{"kevin", "kevin4@google.in", "kevin8@mail.com", "kevin6gfg.org", "kevin7gfg.org", "kevin4@mail.com", "kevin0@mail.com"},
{"levin", "levin8@gmail.com", "levin0gfg.org", "levin1@google.in", "levin7@gmail.com", "levin2@gmail.com", "levin3@mail.com"},
{"bob", "bob2@google.in", "bob2@mail.com", "bob8@google.in", "bob1gfg.org"},
{"levin", "levin8@gmail.com", "levin8@gmail.com", "levin5gfg.org"},
{"alice", "alice2@google.in", "alice8@mail.com", "alice2@mail.com", "alice0@google.in", "alice3gfg.org", "alice2@mail.com", "alice0gfg.org", "alice7@gmail.com"},
{"john", "john2gfg.org", "john8gfg.org"},
{"fern", "fern8gfg.org", "fern2@mail.com", "fern5@mail.com", "fern7gfg.org", "fern4gfg.org", "fern0@gmail.com"},
{"kevin", "kevin9@google.in", "kevin9gfg.org", "kevin8@google.in"},
{"fern", "fern2@google.in"},
{"levin", "levin7@google.in", "levin8@mail.com", "levin9@google.in"},
{"levin", "levin1@mail.com", "levin6@google.in", "levin9gfg.org", "levin0gfg.org", "levin0gfg.org", "levin7@mail.com", "levin1@mail.com", "levin9@google.in", "levin2@mail.com"},
{"mark", "mark7@google.in", "mark5@gmail.com", "mark0@google.in", "mark0gfg.org", "mark7@mail.com", "mark1@mail.com", "mark6@google.in"},
{"alice", "alice3@mail.com", "alice6gfg.org", "alice2gfg.org", "alice8gfg.org", "alice0@mail.com", "alice3gfg.org", "alice8@gmail.com"},
{"bob", "bob7gfg.org", "bob7@google.in", "bob1@mail.com"},
{"fern", "fern0@mail.com", "fern7@google.in", "fern3gfg.org", "fern3@gmail.com", "fern1@google.in", "fern0@gmail.com", "fern1gfg.org"},
{"alice", "alice0@google.in", "alice1@mail.com", "alice0gfg.org", "alice7@google.in", "alice3@mail.com", "alice0gfg.org", "alice7@gmail.com", "alice3@gmail.com"},
{"levin", "levin9@mail.com", "levin6@google.in", "levin6@google.in", "levin9@gmail.com"},
{"levin", "levin4@mail.com", "levin6@google.in"},
{"john", "john7@google.in", "john0@mail.com", "john7@gmail.com", "john6@google.in", "john5@google.in", "john3@google.in", "john6@mail.com", "john4@gmail.com"},
{"kevin", "kevin2@gmail.com", "kevin8gfg.org", "kevin9@google.in", "kevin7@gmail.com", "kevin1gfg.org"},
{"alice", "alice5@google.in", "alice7gfg.org", "alice2@google.in", "alice2@mail.com", "alice7@mail.com", "alice0@gmail.com", "alice5@mail.com", "alice8@google.in"},
{"kevin", "kevin6gfg.org", "kevin3@google.in"},
{"john", "john0@mail.com", "john9@google.in", "john5@google.in", "john8@gmail.com", "john2@gmail.com"},
{"kevin", "kevin4gfg.org", "kevin8@google.in", "kevin2@mail.com", "kevin6gfg.org", "kevin2@mail.com"},
{"kevin", "kevin4@gmail.com"},
{"john", "john0@mail.com", "john3@google.in", "john6@google.in", "john8@google.in", "john7@google.in", "john0@gmail.com", "john4@mail.com"},
{"mark", "mark2@gmail.com", "mark8@google.in", "mark1@google.in", "mark9@google.in", "mark8gfg.org"},
{"bob", "bob9@google.in", "bob1gfg.org"},
{"levin", "levin9@mail.com", "levin3@google.in", "levin8@google.in", "levin7gfg.org", "levin0gfg.org", "levin5@gmail.com", "levin0@gmail.com", "levin0@mail.com"},
{"mark", "mark3@gmail.com", "mark8@google.in", "mark4@google.in", "mark6@gmail.com", "mark7gfg.org"} };
	vector<vector<string>> ans = solu.accountsMerge(vec);
	for (auto a : ans) {
		for (auto b : a) {
			cout << b << " ";
		}
		cout << endl << endl;
	}
	
	


}	