#include <iostream>
#include <algorithm>

using namespace std;
 
bool sortbysec(const pair<string,int> &a, const pair<string,int> &b){
  return (a.second < b.second);
}
 
int main() {
  int casos;
  cin >> casos;
  for(int z = 0; z < casos; z++){
    int equipes;
    cin >> equipes;
    string stringNames[3];
    pair<string, int> arrayFinal[equipes*3];
    pair<string, int> nomes[equipes*3];
    pair<string, string> unknown[equipes*3]; 
    int cnt = 1, cntNomes=0, flag = 0, flagt = 0;
    
    arrayFinal[0].first = "Ahmad";
    arrayFinal[0].second = 0;

    for(int i = 1; i <= equipes; i++){
      cin >> stringNames[0];
      cin >> stringNames[1];
      cin >> stringNames[2];
    
      for(int a = 0; a < 3; a++){
        if(stringNames[a].compare("Ahmad") == 0){
          flagt = 1;
          for(int b = 0; b < 3; b++){
            for(int c = 0; c < cnt; c++){
              if(arrayFinal[c].first.compare(stringNames[b]) == 0) flag = 1;
            }
            if(flag == 0){
              arrayFinal[cnt].first = stringNames[b];
              arrayFinal[cnt++].second = 1;
            }
            flag = 0;
          }
        }
      }
      nomes[cntNomes++].first = stringNames[0];
      nomes[cntNomes++].first = stringNames[1];
      nomes[cntNomes++].first = stringNames[2];
    }

    int num=0, sum=0, weight[3]={10,10,10}, result, unk = 0, crr = 0;

    for(int i = 0; i < equipes; i++){

      stringNames[0] = nomes[crr++].first;
      stringNames[1] = nomes[crr++].first;
      stringNames[2] = nomes[crr++].first;
      
      for(int j = 0; j < cnt; j++){
        if(stringNames[0].compare(arrayFinal[j].first) == 0){
          sum++; weight[0] = arrayFinal[j].second;
        }else if(stringNames[1].compare(arrayFinal[j].first) == 0){
          sum+=3; weight[1] = arrayFinal[j].second;
        }else if(stringNames[2].compare(arrayFinal[j].first) == 0){
          sum+=5; weight[2] = arrayFinal[j].second;
        }
      }
      
      result = weight[2] < (weight[0]<weight[1]?weight[0]:weight[1])?weight[2]:((weight[0]<weight[1])? weight[0]:weight[1]);
      
      if(sum==4){
          arrayFinal[cnt].first = stringNames[1];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==6){
          arrayFinal[cnt].first = stringNames[1];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==1){
          arrayFinal[cnt].first = stringNames[1];
          arrayFinal[cnt].second = result + 1;cnt++;
          arrayFinal[cnt].first = stringNames[2];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==3){
          arrayFinal[cnt].first = stringNames[0];
          arrayFinal[cnt].second = result + 1;cnt++;
          arrayFinal[cnt].first = stringNames[2];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==5){
          arrayFinal[cnt].first = stringNames[0];
          arrayFinal[cnt].second = result + 1;cnt++;
          arrayFinal[cnt].first = stringNames[1];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==8){
          arrayFinal[cnt].first = stringNames[0];
          arrayFinal[cnt].second = result + 1;cnt++;
      }else if(sum==0){
          for(int a = 0; a < 3; a++){
            //arrayFinal[cnt].first = stringNames[i];
            //arrayFinal[cnt].second = 30;
            //cnt++;
            for(int b = 0; b < unk; b++){
              if(stringNames[a].compare(unknown[b].first) == 0) flag = 1;
            }
            if(flag == 0){
                unknown[unk].first = stringNames[a];
                unknown[unk].second = "undefined"; 
                unk++;
            }
          }
      }

      sum=0;
      weight[0] = 10; weight[1] = 10; weight[2] = 10;

    }
    
    stable_sort(arrayFinal, arrayFinal+cnt);
    stable_sort(arrayFinal,arrayFinal+cnt,sortbysec);

    cout << cnt + unk<< endl;
    for(int g=0;g<cnt;g++){
      cout << arrayFinal[g].first << " ";
      if(arrayFinal[g].second != -1) cout << arrayFinal[g].second << endl;
      else cout << "undefined" << endl;
    }
    stable_sort(unknown, unknown+unk);
    for(int g=0;g<unk;g++){
      cout << unknown[g].first << " " << unknown[g].second << endl;
    }
  }
  return 0;
}