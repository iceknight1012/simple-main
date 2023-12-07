from invoke import task
import os
from pathlib import Path
import re

import sys
from subprocess import call
from shutil import rmtree
from os import remove, chmod, unlink
from stat import S_IWRITE


def replaceTextInFile(filePath, old, new):
    file = open(filePath, 'r')
    fileData = file.read()
    file.close()

    fileData = fileData.replace(old, new)

    file = open(filePath, 'w')
    file.write(fileData)
    file.close()


def on_rm_error(func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    chmod(path, S_IWRITE)
    unlink(path)

def get_current_project_name(proj_dir: Path = Path.cwd()):
    cmake_lists_path = proj_dir / "CMakeLists.txt"
    with cmake_lists_path.open(encoding='utf-8') as file:
        for line in file:
            match = re.match(r'project\(([\w\d\-\_]+)', line)
            if match:
                return match.group(1)
    raise ValueError("Project name not found in CMakeLists.txt")


@task
def name(c):
    print(f"Project Name :'{get_current_project_name()}' " )

@task
def rename(c, proj_name):
    """Rename the project, chaning all of the CMake files where the project name appears. """

    old_pn = get_current_project_name()

    print("==> Changing the project name to {0}".format(proj_name))
    replaceTextInFile( f"{proj_name}/CMakeLists.txt",old_pn, proj_name)


