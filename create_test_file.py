import random
import string
import sys

def generate_random_text(size):
    """Generate random text of specified size in bytes."""
    return ''.join(random.choices(string.ascii_letters + string.digits + string.punctuation + ' \n', k=size))

def create_test_file(filename, size_in_kb):
    """Create a test file with random content."""
    size_in_bytes = size_in_kb * 1024
    content = generate_random_text(size_in_bytes)
    
    with open(filename, 'w') as f:
        f.write(content)

    print(f"Created test file '{filename}' of size {size_in_kb} KB.")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_test_file.py <filename> <size_in_kb>")
        sys.exit(1)

    filename = sys.argv[1]
    try:
        size_in_kb = int(sys.argv[2])
    except ValueError:
        print("Error: Size must be an integer")
        sys.exit(1)

    create_test_file(filename, size_in_kb)