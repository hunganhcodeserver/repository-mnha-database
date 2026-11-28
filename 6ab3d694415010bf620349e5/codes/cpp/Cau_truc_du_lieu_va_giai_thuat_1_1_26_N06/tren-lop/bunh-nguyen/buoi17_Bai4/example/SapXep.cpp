#include<iostream>

using namespace std;

void  insertSort(int a[], int n) {
	//Doan da sap: coi a[0] la doan da co thu tu, lan luot chen a[1], a[2],... vao
	for(int i = 1; i < n ; i++) {
		//luu phan tu can chen
		int x = a[i];
		//vi tri cuoi cung cua doan da sap xep
		int j = i -1;

		        //dich cac phan tu lon hon x sang ben phai
		while(j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		//dat x vao cho trong
		a[j+1] = x;
	}
}


void selectionSort(int a[],int n) {
	for(int i = 0 ; i < n - 1 ; i++) {
		//xem a[i] la phan tu nho nhat
		int min = i;
		//tim vi tri phan tu nho nhat trong doan con lai
		for(int j = i+1; j < n; j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}

		//Hoan doi: neu min khac i thi doi cho a[i] voi a[min]
		if(min != i ) {
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
}


void bubbleSort(int a[], int n) {
	//Lap lai n - 1 luot, moi luot phan tu lon nhat noi ve cuoi
	for(int i = 0; i < n -1 ; i++) {
		for(int j = 0; j < n - 1 - i; j++) {
			//kiem tra 2 phan tu dung canh nhau
			if(a[j] > a[j+1]) {
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}


bool binary_search(int *a,int L,int R,int x) {
	//Dieu kien dung: doan rong thi khong tim thay
	if(L > R) {
		return false;
	}

	//So voi phan tu giua
	int mid = L + (R - L)/2;

	//tim o giua
	if(a[mid] == x) {
		return true;
	}
	//tim nua ben trai
	if(x < a[mid]) {
		return binary_search(a,L,mid - 1,x);
	}

	//tim nua ben phai
	else {
		return binary_search(a,mid + 1,R,x );
	}
}

void quickSort(int a[], int L, int R) {
	if(L >= R) {
		return;
	}

	int i = L ;
	int j = R ;

	//Chon chot: lay phan tu o giua doan
	int chot = a[L + (R - L)/2] ;

	//Phan hoach: lap den khi i vuot qua j
	while(i <= j){
		//tim phan tu ben trai  
		while(a[i] < chot){
			i++;
		}

		//tim phan tu ben phai 
		while (a[j] > chot){
			j--;
		}
		
		//neu i <= j thi doi cho hai phan tu
		if(i <= j){
			int tmp = a[i];
			a[i] = a[j];
			a[j] =  tmp;
			
			i++; 
			j--;
		}
	}
	
	//De quy
	//sap xep doan con ben trai 
	quickSort(a,L , j);
	
	//sap xep doan con ben phai 
	quickSort(a,i ,R);
	

}
//Heap sort
void vunDong (int a[] , int n , int i){
	int max = i;
	//Dong cuc dai: con trai 2i + 1, con phai 2i + 2
	int trai = 2 * i + 1;
	int phai = 2 * i + 2; 
	
	//so sanh voi con trai neu con trai ton tai 
	if(trai < n && a[trai] > a[max]){
		max = trai ;
	}
	
	//so sanh voi con phai neu con phai ton tai 
	if(phai < n && a[phai] > a[max]){
		max = phai;
	}
	
	//Vun dong: co con lon hon thi doi cho voi con lon nhat roi vun tiep nhanh do
	if(max != i){
		int tmp = a[i];
		a[i] = a[max];
		a[max] = tmp;
		
		vunDong(a,n,max);
	}
}

void heapSort(int a[],int n){
	//tao dong cuc dai 
	for(int i = n / 2 - 1 ; i>= 0 ; i--){
		vunDong(a,n,i);
	}
	
	// Dua phan tu lon nhat ve cuoi 
	for(int i = n - 1 ; i > 0 ; i--){
		int  tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		//vun dong i phan tu, chay tu 0 den i -1;
		vunDong(a,i,0);
	}
	
}


//MergeSort 
void tron (int a[], int L , int mid ,int R){
	int *tmp = new int [R - L + 1];
	int i = L , j = mid + 1 , k = 0;
	//Tron: chon phan tu nho hon o dau hai doan 
	while(i<= mid && j <=R ){
		if(a[i] <= a[j]){
			tmp[k++] = a[i++];
		//	i++;
		}else{
			tmp[k++] = a[j++];
			//j++
		}
		//k++;
	}
	
	//chep not phan con lai cua nua trai
	while(i <= mid){
		tmp[k++] = a[i++];
		//k++;
		//i++;
	}
	
	//chep not phan con lai cua nua phai
	while(j <= R){
		tmp[k++] = a[j++];
	}
	
	//chep mang tam ve lai a
	for(int z = 0 ; z < k ; z++){
		a[L + z] = tmp[z];
	}
	//giai phong mang tam
	delete[] tmp;
}

void mergeSort(int a[],int L , int R){
	if(L >= R){
		return;
	}
	
	//Chia: chia doi tai mid
	int mid = L + (R - L)/ 2;
	//sap xep nua trai 
	mergeSort(a,L,mid);
	
	//sap xep nua phai
	mergeSort(a, mid + 1,R);
	
	//tron hai nua lai voi nhau 
	tron(a,L ,mid ,R);
}

