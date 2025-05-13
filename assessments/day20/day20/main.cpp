void generate_Reports(const string std_dept[], int std_count) {
    if (std_count == 0) {
        cout << "No students to generate reports.\n";
        return;
    }

    cout << "\n--- Department Reports ---\n";
    for (int i = 0; i < std_count; i++) {
        int deptCount = 1;
        if (i == 0 || std_dept[i] != std_dept[i - 1]) {
            for (int j = i + 1; j < std_count; j++) {
                if (std_dept[i] == std_dept[j]) {
                    deptCount++;
                }
            }
            cout << "Department: " << std_dept[i] << ", Total Students: " << deptCount << "\n";
        }
    }
}