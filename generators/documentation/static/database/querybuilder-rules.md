Below will be listed all the query builder rules available.

|       Rule      |                                                                           Description                                                                           |
|:---------------:|:---------------------------------------------------------------------------------------------------------------------------------------------------------------:|
|    `nullable`   |                                                                  Marks the column as nullable.                                                                  |
|    `integer`    |                                                               Sets the column to an integer type.                                                               |
|     `string`    |                                                                Sets the column to a string type.                                                                |
|    `boolean`    |                                                                Sets the column to a boolean type.                                                               |
|      `date`     |                                                                 Sets the column to a date type.                                                                 |
|    `datetime`   |                                                               Sets the column to a datetime type.                                                               |
|   `min:VALUE`   | Sets the minimum value for the column. If the column is an integer, and the value is >= than 0, it will change it to unsigned integer. |
|   `max:VALUE`   |                                                               Sets the maximum length of a string.                                                              |
|      `json`     |                                                                 Marks the column as a JSON type.                                                                |
|     `float`     |                                                                Marks the column as a float type.                                                                |
| `default:VALUE` |                                                               Sets the default value for a column.                                                              |
|     `unique`    |                                                                   Marks the column as unique.                                                                   |
|    `primary`    |                                                                   Marks the column as primary.                                                                  |
|     `index`     |                                                                    Marks the column as index.                                                                   |
| `autoincrement` |                                                                Sets the column to auto increment.                                                               |