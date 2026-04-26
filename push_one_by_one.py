import subprocess
import os

def run_command(command):
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    return result.stdout.strip().split('\n')

def push_files():
    # Get untracked files
    untracked = run_command('git ls-files --others --exclude-standard')
    # Get modified files
    modified = run_command('git ls-files --modified')
    
    all_files = list(set(untracked + modified))
    all_files = [f for f in all_files if f and not f.endswith('.exe') and os.path.isfile(f)]
    all_files.sort()

    print(f"Found {len(all_files)} files to push.")

    for i, file_path in enumerate(all_files):
        print(f"[{i+1}/{len(all_files)}] Processing {file_path}...")
        
        # Add the file
        subprocess.run(['git', 'add', file_path])
        
        # Determine commit message
        basename = os.path.basename(file_path)
        name_no_ext = os.path.splitext(basename)[0]
        
        if file_path in untracked:
            msg = f"feat: add {name_no_ext} implementation"
        else:
            msg = f"refactor: update {name_no_ext}"
            
        # Try to make it more specific based on path
        if 'BT' in file_path or 'tree' in file_path.lower():
            msg += " for Binary Tree"
        elif 'Graph' in file_path:
            msg += " for Graph algorithms"
        elif 'DP' in file_path:
            msg += " for Dynamic Programming"
        elif 'sorting' in file_path.lower():
            msg += " for Sorting algorithms"
        elif 'Stack' in file_path:
            msg += " for Stack data structure"
        elif 'Queue' in file_path:
            msg += " for Queue data structure"
        elif 'array' in file_path.lower():
            msg += " for Array problems"
            
        subprocess.run(['git', 'commit', '-m', msg])
        
        # Push the change
        print(f"Pushing {file_path}...")
        subprocess.run(['git', 'push'])

if __name__ == "__main__":
    push_files()
