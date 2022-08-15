#include <iostream>
#include <vector>
#include <bits/stdc++.h>
typedef long long lli;
using namespace std;

//Merge sort tirado de https://big-o.io/examples/merge-sort/c++/ Comentarios originais foram removidos
void merge(std::vector<lli> &arr, int start, int middle, int end) {

    std::vector<lli> leftArray(middle - start + 1);
    std::vector<lli> rightArray(end - middle);

    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    int leftIndex = 0, rightIndex = 0;

    int currentIndex = start;

    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

void mergeSort(std::vector<lli> &arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

void Divide(vector<lli>& a,unordered_set<lli>& busca)
{                  //mn é um numero grande
	lli soma=0,mx=0,mn=1e9,mid=0;

    //encontra maior e menor numero do vetor
	for(int i=0;i<a.size();i++)
	{
		soma+=a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	busca.insert(soma);

    //mx e mn não pode ser iguais
	if(mx==mn)
		return;

	mid=(mn+mx)/2;
    
	vector<lli> esquerda,direita; 
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>mid)
			direita.push_back(a[i]);
		else
			esquerda.push_back(a[i]);
	}
	Divide(esquerda,busca);
	Divide(direita,busca);
}

int main()
{
    int Ntests, size, prettyN, compara;

    cin >> Ntests; 

    for(int j=0; j<Ntests; j++)
    {
        cin >> size >> prettyN;
        vector<lli> array(size);
        unordered_set<lli> IsPretty;

        for(int i=0; i<size; i++)
        {
            cin >> array[i];
        }

        mergeSort(array, 0, size-1);
        Divide(array,IsPretty);

        for(int i=0; i<prettyN; i++)
        {
            cin >> compara;
            if(IsPretty.find(compara) == IsPretty.end())
            {
                cout << "NO" << endl;
            }
            else cout << "YES" << endl;
        }

        IsPretty.clear();
    }

    return 0;
}