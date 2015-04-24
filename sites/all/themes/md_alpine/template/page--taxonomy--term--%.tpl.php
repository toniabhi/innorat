<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<section class="section-content blog-content">
    <!-- Section title -->
    <div class="section-title text-center">
        <h1><?php print drupal_get_title();?></h1>
    </div>
    <!-- Section title -->
    <div class="container">
        <div class="row">
            <div class="col-md-12">
                <?php print $messages; ?>
                <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
            </div>
            <?php if($page['content']):?>
                <div class="col-md-12">
                    <?php print render($page['content']);?>
                </div>
            <?php endif;?>
        </div>
    </div>
</section>
<?php if($page['footer']):?>
    <?php print render($page['footer']);?>
<?php endif;?>
<!-- Back to top -->
<a href="#" id="back-top"><i class="fontello icon-angle-up icon-2x"></i></a>