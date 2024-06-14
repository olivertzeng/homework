#!/bin/bash

fd -e tex -x sh -c 'cd {//} && xelatex -interaction=nonstopmode -shell-escape -8bit -recorder {/.} && cd -'
