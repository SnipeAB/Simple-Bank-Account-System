# Design Document – Online Shop "Buy 5, Get the Cheapest Free"

## 1. Problem
A customer buys five items. The program takes in each product and its cost,
displays them by price (highest to lowest), discounts the cheapest item, and
displays the total owed. It must use procedures and user-defined functions.

## 2. Inputs / Processes / Outputs

| Inputs | Processes | Outputs |
|---|---|---|
| 5 item names | Sort items by price, highest to lowest | Items listed highest to lowest price |
| 5 item prices | Add up the 4 most expensive prices (cheapest is free) | Total owed |

## 3. Procedures and functions

| Name | Type | Parameters | Returns | Purpose |
|---|---|---|---|---|
| `readName` | Function | itemNum | string | Read one item's name |
| `readInput` | Function | itemNum | double | Read one item's price |
| `getItems` | Procedure | names[], prices[] | – | Get all 5 items |
| `sortItems` | Procedure | names[], prices[] | – | Sort highest price first |
| `displayItems` | Procedure | names[], prices[] | – | Show sorted items |
| `calculateTotal` | Function | prices[] | double | Add up all but the cheapest |
| `displayTotal` | Procedure | total | – | Show total owed |

## 4. Data dictionary (no global variables)

| Name | Data type | Where | Description |
|---|---|---|---|
| names | string array [5] | main | Item names |
| prices | double array [5] | main | Item prices |
| total | double | main / calculateTotal | Total owed |
| name | string | readName | Name entered |
| input | double | readInput | Price entered |
| i, pass | int | loops | Loop counters |

## 5. Top level algorithm

1. Get the names and prices of the five items
2. Sort the items by price from highest to lowest
3. Display the sorted items
4. Calculate the total, leaving out the cheapest item
5. Display the total owed

## 6. Pseudocode

```
PROCEDURE main
    DECLARE names[5] AS STRING
    DECLARE prices[5] AS REAL
    DECLARE total AS REAL
    getItems(names, prices)
    sortItems(names, prices)
    displayItems(names, prices)
    SET total TO calculateTotal(prices)
    displayTotal(total)
END PROCEDURE

FUNCTION readName(itemNum) RETURNS STRING
    SEND "Enter the name of item " & itemNum TO DISPLAY
    RECEIVE name FROM KEYBOARD
    RETURN name
END FUNCTION

FUNCTION readInput(itemNum) RETURNS REAL
    SEND "Enter the price for item " & itemNum TO DISPLAY
    RECEIVE input FROM KEYBOARD
    RETURN input
END FUNCTION

PROCEDURE getItems(names, prices)
    FOR i FROM 0 TO 4 DO
        SET names[i] TO readName(i + 1)
        SET prices[i] TO readInput(i + 1)
    END FOR
END PROCEDURE

PROCEDURE sortItems(names, prices)
    FOR pass FROM 0 TO 3 DO
        FOR i FROM 0 TO 3 DO
            IF prices[i] < prices[i + 1] THEN
                SWAP prices[i] WITH prices[i + 1]
                SWAP names[i] WITH names[i + 1]
            END IF
        END FOR
    END FOR
END PROCEDURE

PROCEDURE displayItems(names, prices)
    SEND "Items from highest to lowest price:" TO DISPLAY
    FOR i FROM 0 TO 4 DO
        SEND names[i] & " - " & prices[i] TO DISPLAY
    END FOR
END PROCEDURE

FUNCTION calculateTotal(prices) RETURNS REAL
    SET total TO 0
    FOR i FROM 0 TO 3 DO          // skip item 5, the cheapest
        SET total TO total + prices[i]
    END FOR
    RETURN total
END FUNCTION

PROCEDURE displayTotal(total)
    SEND "Total owed: " & total TO DISPLAY
END PROCEDURE
```

## 7. Test plan

| Test | Input prices | Expected total | Actual |
|---|---|---|---|
| Normal | 5, 40, 2.50, 80, 15 | 140.00 | 140.00 |
| Equal prices | 10, 10, 10, 10, 10 | 40.00 | 40.00 |
| Zero price | 0, 1, 2, 3, 4 | 10.00 | 10.00 |
