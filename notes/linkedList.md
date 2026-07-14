`int *ptr = &x;`
    ⬆ tag to tell the compiler "ptr is an address not value(like a property tag)"
`printf("%d", *ptr);`
              ⬆ tag to tell the compiler "take value from address *ptr"
