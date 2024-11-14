int fifo(int pages[], int n, int frames) {
    Queue q = createQueue(frames);
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        if (!isInQueue(q, pages[i])) {
            if (isFull(q)) dequeue(q);  // Remove oldest page if full
            enqueue(q, pages[i]);        // Insert new page
            pageFaults++;
        }
    }
    return pageFaults;
}
