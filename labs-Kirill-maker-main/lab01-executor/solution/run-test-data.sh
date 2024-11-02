#!/bin/bash
set -euo pipefail
[ "$#" -ge 1 ] || (echo "Expected at least one argument: command to run" && exit 1)
COMMAND=("$@")
TIMEOUT=15s  # Careful of Valgrind

FAIL=0
# Warning: use \033 instead of \e for compatibility with old Bash on macOS.

function test_ok {
    rm -f test-data/"$1".out

    timeout -k 0.1s "$TIMEOUT" "${COMMAND[@]}" <test-data/"$1".in | head -c 1000000 >test-data/"$1".out
    EXITCODE=${PIPESTATUS[0]}
    case "$EXITCODE" in
    0)
        CUR_OK=0
        diff test-data/"$1".{sol,out} && CUR_OK=1
        if [[ $CUR_OK == 1 ]]; then
          echo PASS
        else
          echo -e "\033[31;1mWA\033[0m"
          FAIL=1
        fi
        ;;
    124)
        echo -e "\033[31;1mTL\033[0m (or exit code $EXITCODE)"
        FAIL=1
        return 1
        ;;
    *)
        echo -e "\033[31;1mRTE\033[0m (exit code $EXITCODE)"
        FAIL=1
        ;;
    esac
    return 0
}

for tn in $(cat tests.txt); do
    tn=$(echo $tn)  # To remove \r from tests.txt on Windows
    echo ===== $tn =====
    if ! test_ok "$tn"; then break; fi
done
if [[ "$FAIL" == "0" ]]; then
    echo -e "===== \033[32;1mALL PASS\033[0m ====="
else
    echo -e "===== \033[31;1mSOME FAIL\033[0m ====="
fi
exit $FAIL
