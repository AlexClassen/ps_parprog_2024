EXEC_FILES := fast medium slow

all: $(EXEC_FILES)

%: %.c
	clang -Xclang -fopenmp -L/opt/homebrew/opt/libomp/lib -I/opt/homebrew/opt/libomp/include -lomp $< -o $@ 

.PHONY: clean
clean:
	rm -f $(EXEC_FILES)

# "You have three C files: fast.c, medium.c, and slow.c. Compile each of these files into executables named fast,
# medium, and slow. And make it a MakeFile" prompt. 
# ChatGPT, 3.5, OpenAI, 8 Mar. 2024. https://chat.openai.com.