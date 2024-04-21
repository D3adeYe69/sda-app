#include <stdio.h>
#include <string.h>

// Hardcoded credentials (for demonstration purposes only)
#define USERNAME "user123"
#define PASSWORD "pass4567"

// Function to remove newline character from a string
void removeNewline(char *str) {
    char *newlinePos = strchr(str, '\n');
    if (newlinePos != NULL) {
        *newlinePos = '\0';
    }
}

// Function to authenticate user
int authenticateUser(const char *username, const char *password) {
    // Check if the provided username and password match the hardcoded credentials
    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

int main() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    removeNewline(username); // Remove newline character if present

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    removeNewline(password); // Remove newline character if present

    // Authenticate the user
    if (authenticateUser(username, password)) {
        printf("Authentication successful. Welcome!\n");
        // Place your banking operations or further logic here
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }

    return 0;
}
