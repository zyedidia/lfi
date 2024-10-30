#!/bin/sh

# Used to count the number of legal/illegal instructions tracked by the
# verifier.
# Usage example: ./count.sh arm64/base.instrs

ALLOWED=$(grep "^case" $1 | wc -l)
DISALLOWED=$(grep "^//" $1 | wc -l)
TOTAL=$((ALLOWED + DISALLOWED))

echo "allowed: $ALLOWED/$TOTAL"
echo "disallowed: $DISALLOWED/$TOTAL"
