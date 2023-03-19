#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int main() {
    ifstream input_file("test.inp");
    ofstream output_file("test.out");

    int n = 0;
    input_file >> n;

    vector<tuple<string, string, string>> v;

    // 튜플을 이용하여 각각의 정보 읽기
    for (int i = 0; i < n; i++) {
        string id;
        string first_name, last_name;
        input_file >> id >> first_name >> last_name;
        v.push_back(make_tuple(id, first_name, last_name));
    }

    // 고유번호를 기준으로 오름차순 정렬
    sort(v.begin(), v.end());

    int Max_fn = 0;//가장 긴  First name
    for (auto a : v) {
        string id;
        string first_name, last_name;
        tie(id, first_name, last_name) = a;
        Max_fn = max(Max_fn, (int)first_name.length());
    }
    int ln_start = Max_fn + 1;

    //파일 출력
    for (auto b : v) {
        string id;
        string first_name, last_name;
        tie(id, first_name, last_name) = b;
        output_file << id << " " << first_name;
        for (int i = 0; i < ln_start - first_name.length(); i++) {//First name의 길이에 따른 길이 조정
            output_file << " ";
        }
        output_file << last_name << endl;
    }

    // map을 이용하여 last name의 빈도수를 계산
    map<string, int> ln_count;
    for (auto c : v) {
        string id;
        string first_name, last_name;
        tie(id, first_name, last_name) = c;
        ln_count[last_name]++;
    }

    // 빈도수가 2 이상인 last name들을 파일에 출력
    bool last_name_output = true;
    for (auto d : ln_count) {
        string last_name = d.first;
        int count = d.second;
        if (count > 1) {
            if (last_name_output) {
                // 첫 번째 중복 last name 출력 전에 개행 문자 삽입
                output_file << endl;
                last_name_output = false;
            }
            output_file << last_name << " " << count << endl;
        }
    }

    input_file.close();
    output_file.close();
    return 0;
}
