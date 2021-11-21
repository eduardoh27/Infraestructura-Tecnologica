int main(int num1, int num2, int num3) {
    
    int m = 0;

    __asm{
        mov eax, m
        mov ebx, num1
        mov ecx, num2
        mov edx, num3

        cmp ebx, ecx
        jle elif
        cmp ebx, edx
        jle elif
        mov eax, ebx
        jmp fin

        elif:
        cmp ecx, ebx
        jle els
        cmp ecx, edx
        jle els
        mov eax, ecx
        jmp fin

        els:
        mov eax, edx

        fin:


    }
}