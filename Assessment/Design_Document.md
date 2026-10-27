# Design Document – Online Shop "Buy 5, Get the Cheapest Free"

## 1. Problem
A customer buys five items. The program takes in each product and its cost,
displays them by price (highest to lowest), discounts the cheapest item, and
displays the total owed. It must use procedures and user-defined functions.

## 2. Inputs / Processes / Outputs

| Inputs | Processes | Outputs |
|---|---|---|
| 5 item names | Validate each price (number, not negative) | Items listed highest to lowest price |
| 5 item prices | Sort items by price, high to low | Subtotal |
| | Add up all prices (subtotal) | The free (cheapest) item |
| | Subtract cheapest price from subtotal | Total owed |

## 3. Modules (procedures and functions)

| Name | Type | Parameters | Returns | Purpose |
|---|---|---|---|---|
| `readName` | Function | itemNum | string | Read one item's name |
| `readInput` | Function | itemNum | double | Read and validate one item's price |
| `getItems` | Procedure | names[], prices[] | – | Fill arrays with all 5 items |
| `sortItems` | Procedure | names[], prices[] | – | Bubble sort, highest price first |
| `displayItems` | Procedure | names[], prices[] | – | Show sorted list |
| `calculateSubtotal` | Function | prices[] | double | Sum of all prices |
| `calculateTotal` | Function | prices[] | double | Subtotal minus cheapest price |
| `displayTotal` | Procedure | names[], prices[] | – | Show subtotal, free item, total |

## 4. Data dictionary

| Name | Data type | Scope | Description |
|---|---|---|---|
| NUM_ITEMS | const int | Global | Number of items in the deal (5) |
| names | string array [5] | main | Item names |
| prices | double array [5] | main | Item prices |
| input | double | readInput | Price entered by user |
| name | string | readName | Name entered by user |
| total | double | calculateSubtotal | Running total |
| pass, i | int | loops | Loop counters |

## 5. Top level algorithm

1. Get the names and prices of the five items
2. Sort the items by price from highest to lowest
3. Display the sorted items
4. Calculate the total owed, discounting the cheapest item
5. Display the subtotal, the free item and the total owed

## 6. Pseudocode (stepwise refinement)

```
CONSTANT NUM_ITEMS = 5

PROCEDURE main
    DECLARE names[NUM_ITEMS] AS STRING
    DECLARE prices[NUM_ITEMS] AS REAL
    SEND "=== Buy 5, Get the Cheapest Free ===" TO DISPLAY
    getItems(names, prices)
    sortItems(names, prices)
    displayItems(names, prices)
    displayTotal(names, prices)
END PROCEDURE

FUNCTION readName(itemNum) RETURNS STRING
    SEND "Enter the name of item " & itemNum TO DISPLAY
    RECEIVE name FROM KEYBOARD
    RETURN name
END FUNCTION

FUNCTION readInput(itemNum) RETURNS REAL
    SEND "Enter the price for item " & itemNum TO DISPLAY
    RECEIVE input FROM KEYBOARD
    WHILE input is not a number OR input < 0 DO
        SEND "Invalid price. Please enter a positive number" TO DISPLAY
        RECEIVE input FROM KEYBOARD
    END WHILE
    RETURN input
END FUNCTION

PROCEDURE getItems(names, prices)
    FOR i FROM 0 TO NUM_ITEMS - 1 DO
        names[i]  = readName(i + 1)
        prices[i] = readInput(i + 1)
    END FOR
END PROCEDURE

PROCEDURE sortItems(names, prices)          // bubble sort, descending
    FOR pass FROM 0 TO NUM_ITEMS - 2 DO
        FOR i FROM 0 TO NUM_ITEMS - 2 - pass DO
            IF prices[i] < prices[i + 1] THEN
                SWAP prices[i] WITH prices[i + 1]
                SWAP names[i]  WITH names[i + 1]
            END IF
        END FOR
    END FOR
END PROCEDURE

PROCEDURE displayItems(names, prices)
    SEND "Items sorted by price (highest to lowest):" TO DISPLAY
    FOR i FROM 0 TO NUM_ITEMS - 1 DO
        SEND (i + 1) & ". " & names[i] & "  " & prices[i] (2 d.p.) TO DISPLAY
    END FOR
END PROCEDURE

FUNCTION calculateSubtotal(prices) RETURNS REAL
    SET total TO 0
    FOR i FROM 0 TO NUM_ITEMS - 1 DO
        SET total TO total + prices[i]
    END FOR
    RETURN total
END FUNCTION

FUNCTION calculateTotal(prices) RETURNS REAL
    // list is sorted, so the cheapest item is the last one
    RETURN calculateSubtotal(prices) - prices[NUM_ITEMS - 1]
END FUNCTION

PROCEDURE displayTotal(names, prices)
    SEND "Subtotal: " & calculateSubtotal(prices) TO DISPLAY
    SEND "Free item: " & names[NUM_ITEMS - 1] & " (-" & prices[NUM_ITEMS - 1] & ")" TO DISPLAY
    SEND "Total owed: " & calculateTotal(prices) TO DISPLAY
END PROCEDURE
```

## 7. Test plan

| Test | Input prices | Expected | Actual |
|---|---|---|---|
| Normal | 5, 40, 2.50, 80, 15 | Sorted 80, 40, 15, 5, 2.50; total 140.00 | As expected |
| Equal prices | 10, 10, 10, 10, 10 | Total 40.00 | As expected |
| Zero price | 0, 1, 2, 3, 4 | Total 10.00 | As expected |
| Invalid (text) | "abc" | Error message, asked again | As expected |
| Invalid (negative) | -5 | Error message, asked again | As expected |
