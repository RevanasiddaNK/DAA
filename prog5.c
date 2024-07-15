#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stud {
    int usn;
    char name[50];
    int sem;
};

int partition(int arr[], int low, int high) {
    int key = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        
        while (i < high && arr[i] <= key)
            i++;
        while (arr[j] > key)
            j--;

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            int temp = arr[low];
            arr[low] = arr[j];
            arr[j] = temp;
            return j;
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    struct stud students[10];
    int usnArr[10];
    int n;
    printf("Enter number of students: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter details of student number %d\n", i + 1);

        printf("USN: ");
        scanf("%d", &students[i].usn);
        usnArr[i] = students[i].usn;

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Semester: ");
        scanf("%d", &students[i].sem);
    }

    clock_t st, ed;
    st = clock();
    quickSort(usnArr, 0, n - 1);
    ed = clock();

    printf("Sorted USNs are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", usnArr[i]);
    }

    double timetaken = ((double)(ed - st)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", timetaken);

    return 0;
}
