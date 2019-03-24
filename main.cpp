#include <iostream>

void merge(int arr[], int l, int m, int r){

    int n1 = m - l + 1;
    int n2 =  r - m;

    int left[n1];
    for(int i=0; i<n1; i++){
        left[i]=arr[l+i];
    }

    int right[n2];
    for(int i=0; i<n2; i++){
        right[i]=arr[m+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i < n1 && j < n2){

        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }

        k++;

    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

}

void mergeSort (int arr[], int l,  int r) {
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    int arr[] = {2,4,9,1,3,8,7,11,3,5};

    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0])-1;

    mergeSort(arr, l, r);

    for(int i=0; i<=r; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
