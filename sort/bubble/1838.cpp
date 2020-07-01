
/*
#include <iostream>

using namespace std;

int main(){
    int size, count, flag, temp;
    
    cout << "Size : ";
    cin >> size;
    int* arr;
    arr = new int [size];        // 동적 배열 생성
    
    // 입력 받기
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    

for (int i=0; i<size; i++) {
    flag = 0;
    count = i;
    for (int j=0; j<size-1; j++) {
        if (arr[j] > arr[j+1]) {
            flag = 1;
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    if (flag == 0) {
        break;
    }
}
cout << count;
cout << endl;
    
    // 배열 삭제하기
    delete[] arr;
    
    return 0;
}

*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size, count, flag, max = 0;

    cout << "Size : ";
    cin >> size;

    pair<int, int> *arr = new pair<int, int>[size]; 
    // 동적 배열 생성

    // 입력 받기

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr,arr+size);
    

		for(int i=0;i<size;i++) {
			if (max < arr[i].second - i) {
				max = arr[i].second - i;
			}
		}

    cout << max;
    cout << endl;

    // 배열 삭제하기
    delete[] arr;

    return 0;
}*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size, count, flag, maxNum = 0;

    cout << "Size : ";
    cin >> size;

    pair<int, int> *arr = new pair<int, int>[size];
    // 동적 배열 생성

    // 입력 받기

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + size);// arr부터 size개 까지 

    for (int i = 0; i < size; i++)
    {
        maxNum = max(maxNum, arr[i].second - i);
    }

    cout << maxNum;
    cout << endl;

    // 배열 삭제하기
    delete[] arr;

    return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    int size, temp, maxNum = 0;

    cout << "Size : ";
    cin >> size;

    vector<pair<int, int>> arr;
    // 동적 배열 생성

    // 입력 받기

    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        arr.push_back(pair<int, int>(temp, i));
    }
    sort(arr.begin(), arr.end()); // arr부터 size개 까지

    for (int i = 0; i < size; i++)
    {
        maxNum = max(maxNum, arr[i].second - i);
    }

    cout << maxNum << '\n';

    return 0;
}
*/

/*
결국 실패... 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int size, temp, maxNum = 0;

    cout << "Size : ";
    cin >> size;


    pair<int, int> *arr = new pair<int, int>[500001];

    //pair<int, int> *arr[50000];
    // 배열 생성

    // 입력 받기

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr + size); // arr부터 size개 까지

    for (int i = 0; i < size; i++)
    {
        maxNum = max(maxNum, arr[i].second - i);
    }

    cout << maxNum;
    return 0;
}
*/