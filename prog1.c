#include <stdio.h>
int main() {
int arr[100], size, i, choice, pos, element;
// Taking input for the array
printf("Enter the number of elements in the array: ");
scanf("%d", &size);
printf("Enter %d elements:\n", size);
for (i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
while (1) {
printf("\n1. Insert at position\n");
printf("2. Delete from position\n");
printf("3. Display array\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
if (choice == 1) {
// Insert element
if (size == 100) {
printf("Array is full, cannot insert.\n");
continue;
}
printf("Enter position (0-based index) to insert: ");
scanf("%d", &pos);
if (pos < 0 || pos > size) {
printf("Invalid position! Enter between 0 and %d\n", size);
continue;
}
printf("Enter the element to insert: ");
scanf("%d", &element);
// Shift elements to the right
for (i = size; i > pos; i--) {
arr[i] = arr[i - 1];
}
arr[pos] = element;
size++;
printf("Element inserted successfully!\n");
}
else if (choice == 2) {
// Delete element
if (size == 0) {
printf("Array is empty, nothing to delete.\n");
continue;
}
printf("Enter position (0-based index) to delete: ");
scanf("%d", &pos);
if (pos < 0 || pos >= size) {
printf("Invalid position! Enter between 0 and %d\n", size - 1);
continue;
}
// Shift elements to the left
for (i = pos; i < size - 1; i++) {
arr[i] = arr[i + 1];
}
size--;
printf("Element deleted successfully!\n");
}
else if (choice == 3) {
// Display array
if (size == 0) {
printf("Array is empty.\n");
} else {
printf("Array elements: ");
for (i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
}
else if (choice == 4) {
// Exit program
printf("Exiting program.\n");
break;
}
else {
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}

/* 
             **OUTPUT**

Enter the number of elements in the array: 10
Enter 10 elements:
50                                                 
41
52
52
15
63
65
65
56
65

1. Insert at position
2. Delete from position
3. Display array
4. Exit
Enter your choice: 1
Enter position (0-based index) to insert: 5
Enter the element to insert: 91
Element inserted successfully!

1. Insert at position
2. Delete from position
3. Display array
4. Exit
Enter your choice: 3
Array elements: 50 41 52 52 15 91 63 65 65 56 65 

1. Insert at position
2. Delete from position
3. Display array
4. Exit
Enter your choice: 2
Enter position (0-based index) to delete: 5 
Element deleted successfully!

1. Insert at position
2. Delete from position
3. Display array
4. Exit
Enter your choice: 3
Array elements: 50 41 52 52 15 63 65 65 56 65 

1. Insert at position
2. Delete from position
3. Display array
4. Exit
Enter your choice: 4
Exiting program.


...Program finished with exit code 0
Press ENTER to exit console.



*/
