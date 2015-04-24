<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php
    $count = count($rows);
    $divider = 12 % $count;
    if ($divider = 0) {
        $column_type = 12 / $count;
    } elseif($divider = 7 ) {
        $column_type = 2;
    } elseif ($divider = 5) {
        $column_type = 2;
    } elseif ($divider = 4) {
        $column_type = 4;
    } elseif ($divider = 3) {
        $column_type = 4;
    } elseif ($divider = 2) {
        $column_type = 3;
    } else {
        $column_type = 2;
    }
?>

    <?php foreach ($rows as $id => $row): ?>
        <?php print $row; ?>
    <?php endforeach; ?>
</div>