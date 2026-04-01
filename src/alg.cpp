// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int dif = value - arr[i], l = i+1, r = len-1, index = -1;
        while (l <= r) {
            int mid = (r-l)/2 + l;
            if (arr[mid] == dif) {
                r = mid - 1;
                index = mid;
            } else if (arr[mid] < dif) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (index > 0) {
            int rep = index;
            while (rep < len && arr[rep] == dif) {
                count++;
                rep++;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int l = 0, r = len - 1, count = 0;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum > value) {
            r--;
        } else if (sum < value) {
            l++;
        } else if (arr[l] == arr[r]) {
                int n = r - l + 1;
                count += n * (n - 1) / 2;
                break;
        } else {
            int l_val = arr[l], l_count = 0, r_val = arr[r], r_count = 0;;
            while (l <= r && arr[l] == l_val) {
                l++;
                l_count++;
            }
            while (l < r && arr[r] == r_val) {
                r--;
                r_count++;
            }
            count += l_count * r_count;
        }
    }
    return count;
}
