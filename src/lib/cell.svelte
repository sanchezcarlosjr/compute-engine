<script>
  import "../app.css";
  const ENTER = 13;
  let cell = "";
  function onKeyDown(event) {
    if(event.keyCode === ENTER && event.shiftKey) {
      event.preventDefault();
    }
  }
</script>


<div class="grow-wrap" data-replicated-cell={cell}>
  <textarea bind:value={cell} on:keydown={onKeyDown} rows="1"></textarea>
</div>


<style>
    /* https://css-tricks.com/the-cleanest-trick-for-autogrowing-textareas/ */
    .grow-wrap {
        /* easy way to plop the elements on top of each other and have them both sized based on the tallest one's height */
        display: grid;
    }

    .grow-wrap::after {
        /* Note the weird space! Needed to prevent jumpy behavior */
        content: attr(data-replicated-cell) " ";

        /* This is how textarea text behaves */
        white-space: pre-wrap;

        /* Hidden from view, clicks, and screen readers */
        visibility: hidden;
    }

    .grow-wrap > textarea {
        /* You could leave this, but after a user resizes, then it ruins the auto sizing */
        resize: none;

        /* Firefox shows scrollbar on growth, you can hide like this. */
        overflow: hidden;
    }

    .grow-wrap > textarea,
    .grow-wrap::after {
        /* Identical styling required!! */
        border: 1px solid palegreen;
        padding: 0.5rem;
        font: inherit;

        /* Place on top of each other */
        grid-area: 1 / 1 / 2 / 2;
    }
</style>
