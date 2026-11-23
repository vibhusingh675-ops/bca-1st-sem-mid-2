double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int i = 0, j = 0, count = 0;
    int val1 = 0, val2 = 0;

    while (count <= mid2) {
        int current;
        if (i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {
            current = nums1[i++];
        } else {
            current = nums2[j++];
        }

        if (count == mid1) {
            val1 = current;
        }
        if (count == mid2) {
            val2 = current;
        }
        count++;
    }

    return (val1 + val2) / 2.0;
}
