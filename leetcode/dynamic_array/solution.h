class DynamicArray {
public:

    DynamicArray(int capacity) {
        contents = new int[capacity];
        mCapacity = capacity;
        current_end_index = 0;
    }

    int get(int i) {
        return contents[i];
    }

    void set(int i, int n) {
        contents[i] = n;
    }

    void pushback(int n) {
          if( current_end_index == mCapacity ) {

            int *temp = new int[2 * mCapacity];
            for (int i = 0; i < mCapacity; i++){
                temp[i] = contents[i];
            }
            delete[] contents;
            mCapacity *= 2;
            contents = temp;
        }

        contents[current_end_index] = n;
        current_end_index++;
    }

    int popback() {
        if (current_end_index  > 0)  {
        int val = contents[current_end_index];
        current_end_index--;
        return val;
        }
    }

    void resize() {
         int *temp = new int[2 * mCapacity];
            for (int i = 0; i < mCapacity; i++){
                temp[i] = contents[i];
            }
            delete[] contents;
            mCapacity *= 2;
            contents = temp;
    }

    int getSize() {
        return current_end_index;
    }

    int getCapacity() {
        return mCapacity;
    }

private:
    int *contents;
    int mCapacity;
    int current_end_index;
};